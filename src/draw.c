#include "../headers/cub3d.h"
#include "mlx.h"

void    draw_sky(t_struct *datas)
{
    int y;


    y = -1;
    while (++y < screenHeight / 2)
        datas->img.datas[y * screenHeight + datas->algo.x] = 0xf8b195;
}

void    draw_flor(t_struct *datas)
{
    int y;
    

    y = screenHeight / 2;
    while (++y < screenHeight)
        datas->img.datas[y * screenHeight + datas->algo.x] = 0x27496d;
}

void    draw_wall(t_struct *datas)
{
    int y;

    y = datas->algo.drawStart;
    while (y <= datas->algo.drawEnd)
    {
        datas->img.datas[y * screenHeight + datas->algo.x] = datas->img.color;
        y++;
    }
}

void    draw(t_struct *datas)
{
    draw_sky(datas);
    draw_flor(datas);
    draw_wall(datas);
}