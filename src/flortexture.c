#include "../headers/cub3d.h"
#include "mlx.h"

void    define_florwallxandy(t_struct *datas)
{
    if (datas->algo.side == 1 && datas->algo.rayDirX > 0)
    {
        datas->algo.floorxwall = datas->algo.mapX;
        datas->algo.floorywall = datas->algo.mapY + datas->algo.wallX;
    }
    if (datas->algo.side == 0 && datas->algo.rayDirX < 0)
    {
        datas->algo.floorxwall = datas->algo.mapX + 1.0; 
        datas->algo.floorywall = datas->algo.mapY + datas->algo.wallX;
    }
    if (datas->algo.side == 3 && datas->algo.rayDirY > 0)
    {
        datas->algo.floorxwall = datas->algo.mapX + datas->algo.wallX;
        datas->algo.floorywall = datas->algo.mapY;
    }
    if (datas->algo.side == 2 && datas->algo.rayDirY < 0)
    {
        datas->algo.floorxwall = datas->algo.mapX + datas->algo.wallX; 
        datas->algo.floorywall = datas->algo.mapY + 1.0;
    }
}

void    draw_flor_text(t_struct *datas)
{
    int y;

    define_florwallxandy(datas);
    datas->algo.distwall = datas->algo.perpWallDist;
    datas->algo.distplayer = 0.0;
    if (datas->algo.drawEnd < 0)
        datas->algo.drawEnd = datas->game.w_h;
    y = datas->algo.drawEnd;
    while (++y < datas->game.w_h)
    {
        datas->algo.currentdist = datas->game.w_h / (2.0 * y - datas->game.w_h);
        datas->algo.weight = (datas->algo.currentdist - datas->algo.distplayer) /
        (datas->algo.distwall - datas->algo.distplayer);
        datas->algo.currentfloorx = datas->algo.weight * datas->algo.floorxwall +
        (1.0 - datas->algo.weight) * datas->algo.posX;
        datas->algo.currentfloory = datas->algo.weight * datas->algo.floorywall +
        (1.0 - datas->algo.weight) * datas->algo.posY;
        datas->algo.floortexx = (int)(datas->algo.currentfloorx * datas->tex[4].t_w) %
        datas->tex[4].t_w;
        datas->algo.floortexy = (int)(datas->algo.currentfloory * datas->tex[4].t_h) %
        datas->tex[4].t_h;
        datas->game.flor_color = datas->tex[4].datas[datas->tex[4].t_w * datas->algo.floortexy + datas->algo.floortexx];
        datas->img.datas[(datas->game.w_w * y) + datas->algo.x] = datas->game.flor_color;
    }
}