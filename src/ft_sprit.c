#include "../headers/cub3d.h"
#include "mlx.h"

void    init_sprit(t_struct *datas, int i)
{
    datas->algo.s_x = datas->sprit[i].posx - datas->algo.posX + 0.5;
    datas->algo.s_y = datas->sprit[i].posy - datas->algo.posY + 0.5;
    datas->algo.invet = 1.0 / (datas->algo.planeX * datas->algo.dirY
    - datas->algo.dirX * datas->algo.s_y);
    datas->algo.trans_x = datas->algo.invet * (datas->algo.dirY * datas->algo.s_x
    - datas->algo.dirX * datas->algo.planeY);
    datas->algo.trans_y = datas->algo.invet * (-datas->algo.planeY * datas->algo.s_x
    + datas->algo.planeX * datas->algo.s_y);
    datas->algo.screenx = (int)((datas->game.w_w / 2) * (1 + datas->algo.trans_x / datas->algo.trans_y));
    datas->algo.s_h = abs((int)(datas->game.w_h / (datas->algo.trans_y)));
    datas->algo.dstart_x = -datas->algo.s_w / 2 + datas->algo.screenx;
    datas->algo.dstart_x = datas->algo.dstart_x > 0 ? datas->algo.dstart_x : 0;
    datas->algo.dend_x = datas->algo.s_w / 2 + datas->algo.screenx;
    if (datas->algo.dend_x >= datas->game.w_w)
        datas->algo.dend_x = datas->game.w_w - 1;
}