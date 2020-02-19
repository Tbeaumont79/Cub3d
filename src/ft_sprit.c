#include "../headers/cub3d.h"
#include "mlx.h"

void    init_sprit(t_struct *datas, int i)
{
    datas->algo.s_x = datas->sprit[i].posx - datas->algo.posX + 0.5;
    datas->algo.s_y = datas->sprit[i].posy - datas->algo.posY + 0.5;
    datas->algo.invet = 1.0 / (datas->algo.planeX * datas->algo.dirY
    - datas->algo.dirX * datas->algo.planeY);
    datas->algo.trans_x = datas->algo.invet * (datas->algo.dirY * datas->algo.s_x
    - datas->algo.dirX * datas->algo.s_y);
    datas->algo.trans_y = datas->algo.invet * (-datas->algo.planeY * datas->algo.s_x
    + datas->algo.planeX * datas->algo.s_y);
    datas->algo.screenx = (int)((datas->game.w_w / 2) * (1 + datas->algo.trans_x / datas->algo.trans_y));
    datas->algo.s_h = abs((int)(datas->game.w_h / (datas->algo.trans_y)));
    datas->algo.dstart_y = -datas->algo.s_h / 2 + datas->game.w_h / 2;
    datas->algo.dstart_y = datas->algo.dstart_y > 0 ? datas->algo.dstart_y : 0;
    datas->algo.dend_y = datas->algo.s_h / 2 + datas->game.w_h / 2;
    if (datas->algo.dend_y >= datas->game.w_h)
        datas->algo.dend_y = datas->game.w_h - 1;
    datas->algo.s_w = abs((int)(datas->game.w_h / (datas->algo.trans_y)));
    datas->algo.dstart_x = -datas->algo.s_w / 2 + datas->algo.screenx;
    datas->algo.dstart_x = datas->algo.dstart_x > 0 ? datas->algo.dstart_x : 0;
    datas->algo.dend_x = datas->algo.s_w / 2 + datas->algo.screenx;
    if (datas->algo.dend_x >= datas->game.w_w)
        datas->algo.dend_x = datas->game.w_w - 1;
}

void    display_sprit(t_struct *datas, int i)
{
    int y;
    int val;
    int color;

    datas->algo.sprit_tex_x = (int)(256 * (datas->algo.strip - 
    (-datas->algo.s_w / 2 + datas->algo.screenx))
    * datas->sprit[i].w / datas->algo.s_w) / 256;
    if (datas->algo.trans_y > 0 && datas->algo.strip > 0 &&
    datas->algo.strip < datas->game.w_w &&
    datas->algo.trans_y < datas->algo.zbuff[datas->algo.strip])
    {
        y = datas->algo.dstart_y;

        while (y < datas->algo.dend_y)
        {
            val = ((y * 256) - (datas->game.w_h * 128) + (datas->algo.s_h * 128));
            datas->algo.sprit_tex_y =
            ((val * datas->sprit[i].h) / datas->algo.s_h) / 256;
            color = datas->sprit[i].datas[(datas->sprit[i].w * datas->algo.sprit_tex_y
            ) + datas->algo.sprit_tex_x];
            if ((color & 0x00FFFFFF) != 0)
                datas->img.datas[(datas->game.w_w * y) + datas->algo.strip] = color;
            y++;
        }
    }
}

int     get_sprite(t_struct *datas)
{
    int j;

    if (!(datas->sprit = (t_sprit *)malloc(sizeof(t_sprit)
    * datas->game.num_sprit)))
     return (ft_error("malloc !\n"));
    get_sprit_pos(datas);
    j = 0;
    while (j < datas->game.num_sprit)
    {
        if (!(datas->sprit[j].img =
        mlx_xpm_file_to_image(datas->img.ptr, datas->algo.s_name, &datas->sprit[j].w,
        &datas->sprit[j].h)))
            return (ft_error("int path or bad sprit !\n"));
        datas->sprit[j].datas = (int *)mlx_get_data_addr(datas->sprit[j].img,
        &datas->sprit[j].bpp, &datas->sprit[j].size_line, &datas->sprit[j].endian);
        datas->sprit[j].sprite_distance =
        ((datas->algo.posX - datas->sprit[j].posx)
        * (datas->algo.posX - datas->sprit[j].posx)
        + (datas->algo.posY - datas->sprit[j].posy) 
        * (datas->algo.posY - datas->sprit[j].posy));
        j++;
    }
    return (0);
}

int     handle_sprit(t_struct *datas)
{
    int i;

    if ((get_sprite(datas)) == -1)
        return (ft_error("can't get sprit ! \n"));
    sorted_sprite(datas);
    i = -1;
    while (++i < datas->game.num_sprit)
    {
        init_sprit(datas, i);
        datas->algo.strip = datas->algo.dstart_x;
        while (datas->algo.strip < datas->algo.dend_x)
        {
            display_sprit(datas, i);
            datas->algo.strip++;
        }
    }
    free(datas->sprit);
    return (0);
}