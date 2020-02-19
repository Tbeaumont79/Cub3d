#include "../headers/cub3d.h"

double    define_spawn_deg(t_struct *datas)
{
    double deg;

    deg = datas->game.spaw_dir == 'N' ? M_PI_2 : 0;
    deg = datas->game.spaw_dir == 'S' ? -M_PI_2 : 0;
    deg = datas->game.spaw_dir == 'E' ? M_PI : 0;
    deg = datas->game.spaw_dir == 'O' ? -M_PI : 0;
    return (deg);
}

void    init_raycasting_var(t_struct *datas)
{
    int tmp_dirx;
    int old_planex;
    int deg;
    deg = define_spawn_deg(datas);
    datas->algo.dirX = -1;
    datas->algo.dirY = 0;
    tmp_dirx = datas->algo.dirX;
    datas->algo.dirX = datas->algo.dirX * cos(deg) - datas->algo.dirY * sin(deg);
    datas->algo.dirY = tmp_dirx * sin(deg) + datas->algo.dirY * cos(deg);
    datas->algo.planeX = 0;
    datas->algo.planeY = 0.66;
    old_planex = datas->algo.planeX;
    datas->algo.planeX = datas->algo.planeX * cos(deg) - datas->algo.planeY * sin(deg);
    datas->algo.planeY = old_planex * sin(deg) + datas->algo.planeY * cos(deg);    
    datas->algo.moveSpeed = 0.05;
    datas->algo.rotSpeed = 0.05;
}

void    init_raycasting_var_in_loop(t_struct *datas, int w, int h)
{
    (void)h;
    datas->algo.cameraX = 2 * datas->algo.x / (double)w - 1;
    datas->algo.rayDirX =
    datas->algo.dirX + datas->algo.planeX * datas->algo.cameraX;
    datas->algo.rayDirY =
    datas->algo.dirY + datas->algo.planeY * datas->algo.cameraX;
    datas->algo.mapX = (int)datas->algo.posX;
    datas->algo.mapY = (int)datas->algo.posY;
    datas->algo.deltaDistX = (double)fabs(1 / datas->algo.rayDirX);
    datas->algo.deltaDistY = (double)fabs(1 / datas->algo.rayDirY);
    datas->algo.hit = 0;
}

void    check_raycasting(t_struct *datas)
{
    if (datas->algo.rayDirX < 0)
        {
            datas->algo.stepX = -1;
            datas->algo.sideDistX = 
            (datas->algo.posX - datas->algo.mapX) * datas->algo.deltaDistX;
        }
        else
        {
            datas->algo.stepX = 1;
            datas->algo.sideDistX =
            (datas->algo.mapX + 1.0 - datas->algo.posX) * datas->algo.deltaDistX;                
        }
        if (datas->algo.rayDirY < 0)
        {
            datas->algo.stepY = -1;
            datas->algo.sideDistY =
            (datas->algo.posY - datas->algo.mapY) * datas->algo.deltaDistY;
        }
        else
        {
            datas->algo.stepY = 1;
            datas->algo.sideDistY =
            (datas->algo.mapY + 1.0 - datas->algo.posY) * datas->algo.deltaDistY;
        }
}

void    check_hit(t_struct *datas)
{
    while (datas->algo.hit == 0)
    {
        if (datas->algo.sideDistX < datas->algo.sideDistY)
        {
            datas->algo.side = datas->algo.rayDirX < 0 ? 0 : 1;
            datas->algo.sideDistX += datas->algo.deltaDistX;
            datas->algo.mapX += datas->algo.stepX;
        }
        else
        {
            datas->algo.side = datas->algo.rayDirY < 0 ? 2 : 3;
            datas->algo.sideDistY += datas->algo.deltaDistY;
            datas->algo.mapY += datas->algo.stepY;
        }
        if (datas->game.map[datas->algo.mapX][datas->algo.mapY] == 1)
            datas->algo.hit = 1;
    }
}

void    init_calcul_for_draw_wall(t_struct *datas, int w, int h)
{
        (void)w;
        datas->algo.perpWallDist = datas->algo.side == 0 || datas->algo.side == 1 ?
        (datas->algo.mapX - datas->algo.posX + (1 - datas->algo.stepX) / 2)
         / datas->algo.rayDirX : (datas->algo.mapY - datas->algo.posY + 
         (1 - datas->algo.stepY) / 2) / datas->algo.rayDirY;
         datas->algo.lineHeight = (int)(h / datas->algo.perpWallDist);
         datas->algo.drawStart = -datas->algo.lineHeight / 2 + h / 2;
         if (datas->algo.drawStart < 0)
            datas->algo.drawStart = 0;
        datas->algo.drawEnd = datas->algo.lineHeight / 2 + h / 2;
        if (datas->algo.drawEnd >= h)
            datas->algo.drawEnd = h - 1;
        datas->algo.wallX = datas->algo.side == 0 || datas->algo.side == 1 ?
        datas->algo.posY + datas->algo.perpWallDist * datas->algo.rayDirY : 
        datas->algo.posX + datas->algo.perpWallDist * datas->algo.rayDirX;
        datas->algo.wallX -= floor((datas->algo.wallX));
}

int    ft_raycasting(t_struct *datas)
{
    int h;
    int w;

    w = datas->game.w_w;
    h = datas->game.w_h;
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
        datas->algo.zbuff[datas->algo.x] = datas->algo.perpWallDist;
    }
    if (datas->game.num_sprit > 0)
        if ((handle_sprit(datas)) == -1)
            return (ft_error("sprit !"));
    render(datas);
    return (0);
}