#include "../headers/cub3d.h"
#include "mlx.h"

void    draw_sky(t_struct *datas)
{
    int y;

    y = -1;
    while (++y < datas->game.w_h / 2)
        datas->img.datas[(y * datas->game.w_w) + datas->algo.x] = datas->game.rof_color;
}

void    draw_flor(t_struct *datas)
{
    int y;
    
    y = datas->game.w_h / 2;
    while (++y < datas->game.w_h)
        datas->img.datas[(y * datas->game.w_w) + datas->algo.x] = datas->game.flor_color;  
}

void    draw_wall(t_struct *datas)
{
    int y;
    int val;
    int color;

    y = datas->algo.drawStart;
    while (y <= datas->algo.drawEnd)
    {
        val = y * 256 - datas->game.w_h * 128 + datas->algo.lineHeight * 128;
        choose_tex(datas, &color, val);
        datas->img.datas[(y * datas->game.w_w) + datas->algo.x] = color;
        y++;
    }
}

void    draw(t_struct *datas)
{
    init_algo_tex(datas);
    draw_sky(datas);
    draw_flor(datas);
    draw_wall(datas);
}