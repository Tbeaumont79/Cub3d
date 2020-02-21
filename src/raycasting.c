#include "../headers/cub3d.h"
#include "../Libft/libft.h"
double    define_spawn_deg(t_struct *datas)
{
    double deg;

    deg = datas->game.spaw_dir == 'O' ? M_PI_2 : 0;
    deg = datas->game.spaw_dir == 'E' ? -(M_PI_2) : deg;
    deg = datas->game.spaw_dir == 'N' ? 0 : deg;
    deg = datas->game.spaw_dir == 'S' ? -(M_PI) : deg;
    return (deg);
}

void    init_raycasting_var(t_struct *datas)
{
    double tmp_dirx;
    double old_planex;
    double deg;

    deg = define_spawn_deg(datas);
    datas->algo.dirx = -1;
    datas->algo.diry = 0;
    datas->algo.planex = 0;
    datas->algo.planey = 0.66;
    tmp_dirx = datas->algo.dirx;
    datas->algo.dirx = datas->algo.dirx * cos(deg) - datas->algo.diry * sin(deg);
    datas->algo.diry = tmp_dirx * sin(deg) + datas->algo.diry * cos(deg);
    old_planex = datas->algo.planex;
    datas->algo.planex = datas->algo.planex * cos(deg) - datas->algo.planey * sin(deg);
    datas->algo.planey = old_planex * sin(deg) + datas->algo.planey * cos(deg);    
    datas->algo.movespeed = 0.05;
    datas->algo.rotspeed = 0.05;
}

void    init_raycasting_var_in_loop(t_struct *datas, int w, int h)
{
    (void)h;
    datas->algo.camerax = 2 * datas->algo.x / (double)w - 1;
    datas->algo.raydirx =
    datas->algo.dirx + datas->algo.planex * datas->algo.camerax;
    datas->algo.raydiry =
    datas->algo.diry + datas->algo.planey * datas->algo.camerax;
    datas->algo.mapx = (int)datas->algo.posx;
    datas->algo.mapy = (int)datas->algo.posy;
    datas->algo.deltadistx = (double)fabs(1 / datas->algo.raydirx);
    datas->algo.deltadisty = (double)fabs(1 / datas->algo.raydiry);
    datas->algo.hit = 0;
}

void    check_raycasting(t_struct *datas)
{
    if (datas->algo.raydirx < 0)
        {
            datas->algo.stepx = -1;
            datas->algo.sidedistx = 
            (datas->algo.posx - datas->algo.mapx) * datas->algo.deltadistx;
        }
        else
        {
            datas->algo.stepx = 1;
            datas->algo.sidedistx =
            (datas->algo.mapx + 1.0 - datas->algo.posx) * datas->algo.deltadistx;                
        }
        if (datas->algo.raydiry < 0)
        {
            datas->algo.stepy = -1;
            datas->algo.sidedisty =
            (datas->algo.posy - datas->algo.mapy) * datas->algo.deltadisty;
        }
        else
        {
            datas->algo.stepy = 1;
            datas->algo.sidedisty =
            (datas->algo.mapy + 1.0 - datas->algo.posy) * datas->algo.deltadisty;
        }
}

void    check_hit(t_struct *datas)
{
    while (datas->algo.hit == 0)
    {
        if (datas->algo.sidedistx < datas->algo.sidedisty)
        {
            datas->algo.side = datas->algo.raydirx < 0 ? 0 : 1;
            datas->algo.sidedistx += datas->algo.deltadistx;
            datas->algo.mapx += datas->algo.stepx;
        }
        else
        {
            datas->algo.side = datas->algo.raydiry < 0 ? 2 : 3;
            datas->algo.sidedisty += datas->algo.deltadisty;
            datas->algo.mapy += datas->algo.stepy;
        }
        if (datas->game.map[datas->algo.mapx][datas->algo.mapy] == 1)
            datas->algo.hit = 1;
    }
}

void    init_calcul_for_draw_wall(t_struct *datas, int w, int h)
{
        (void)w;
        datas->algo.perpwalldist = datas->algo.side == 0 || datas->algo.side == 1 ?
        (datas->algo.mapx - datas->algo.posx + (1 - datas->algo.stepx) / 2)
         / datas->algo.raydirx : (datas->algo.mapy - datas->algo.posy + 
         (1 - datas->algo.stepy) / 2) / datas->algo.raydiry;
         datas->algo.lineheight = (int)(h / datas->algo.perpwalldist);
         datas->algo.drawstart = -datas->algo.lineheight / 2 + h / 2;
         if (datas->algo.drawstart < 0)
            datas->algo.drawstart = 0;
        datas->algo.drawend = datas->algo.lineheight / 2 + h / 2;
        if (datas->algo.drawend >= h)
            datas->algo.drawend = h - 1;
        datas->algo.wallx = datas->algo.side == 0 || datas->algo.side == 1 ?
        datas->algo.posy + datas->algo.perpwalldist * datas->algo.raydiry : 
        datas->algo.posx + datas->algo.perpwalldist * datas->algo.raydirx;
        datas->algo.wallx -= floor((datas->algo.wallx));
}

int    ft_raycasting(t_struct *datas)
{
    int h;
    int w;

    w = datas->game.w_w;
    h = datas->game.w_h;
    datas->game.check_sprit = 0;
    datas->algo.x = -1;
    if (!(datas->algo.zbuff = malloc(sizeof(double) * datas->game.w_w)))
        return (ft_error("malloc !\n"));
    init_img(datas);
    while (++datas->algo.x < w)
    {
        init_raycasting_var_in_loop(datas, w, h);
        check_raycasting(datas);
        check_hit(datas);
        init_calcul_for_draw_wall(datas, w, h);
        draw(datas);
        datas->algo.zbuff[datas->algo.x] = datas->algo.perpwalldist;
    }
    if (datas->game.num_sprit > 0)
        if ((handle_sprit(datas)) == -1)
            return (ft_error("sprit !"));
    render(datas);
    return (0);
}