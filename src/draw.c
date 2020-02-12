#include "../headers/cub3d.h"
#include "mlx.h"

void    draw_sky(t_struct *datas)
{
    int x;
    int y;

    x = -1;
    while (++x < screenWidth / 2)
    {
        y = -1;
        while (++y < screenHeight)
            datas->img.datas[x * screenHeight + y] = 0x0000FF;
    }
    datas->img.pixel = x;
}

void    draw_flor(t_struct *datas)
{
    int x;
    int y;
    
    x = datas->img.pixel;
    while (++x < screenWidth)
    {
        y = -1;
        while (++y < screenHeight)
            datas->img.datas[x * screenHeight + y] = 0x00FF00;
    }
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
    //draw_sky(datas);
    //draw_flor(datas);
    draw_wall(datas);
    mlx_put_image_to_window(datas->img.ptr, datas->img.win, datas->img.img, 0, 0);
}