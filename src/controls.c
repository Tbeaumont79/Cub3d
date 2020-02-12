#include "../headers/cub3d.h"
#include "mlx.h"
int    quit(t_struct *datas)
{
    exit(EXIT_SUCCESS);
    return (0);
}

int    move_up(t_struct *datas)
{
    if (datas->game.map[(int)(datas->algo.posX + datas->algo.dirX * datas->algo.moveSpeed)]
    [(int)datas->algo.posY] == 0)
        datas->algo.posX += datas->algo.dirX * datas->algo.moveSpeed;
    if (datas->game.map[(int)datas->algo.posX]
    [(int)(datas->algo.posY + datas->algo.dirY * datas->algo.moveSpeed) == 0])
        datas->algo.posY += datas->algo.dirY * datas->algo.moveSpeed;
    return (0);
}

int    move_down(t_struct *datas)
{
        if (datas->game.map[(int)(datas->algo.posX - datas->algo.dirX * datas->algo.moveSpeed)]
    [(int)datas->algo.posY] == 0)
        datas->algo.posX -= datas->algo.dirX * datas->algo.moveSpeed;
    if (datas->game.map[(int)datas->algo.posX]
    [(int)(datas->algo.posY - datas->algo.dirY * datas->algo.moveSpeed) == 0])
        datas->algo.posY -= datas->algo.dirY * datas->algo.moveSpeed;
    return (0);
}

int    move_right(t_struct *datas)
{
    datas->algo.oldDirX = datas->algo.dirX;
    datas->algo.dirX =
    datas->algo.dirX * cos(-datas->algo.rotSpeed) - datas->algo.dirY * sin(-datas->algo.rotSpeed);
    datas->algo.dirY =
    datas->algo.oldDirX * sin(-datas->algo.rotSpeed) + datas->algo.dirY * cos(-datas->algo.rotSpeed);
    datas->algo.oldPlaneX = datas->algo.planeX;
    datas->algo.planeX = 
    datas->algo.planeX * cos(-datas->algo.rotSpeed) - datas->algo.planeY * sin(-datas->algo.rotSpeed);
    datas->algo.planeY =
    datas->algo.oldPlaneX * sin(-datas->algo.rotSpeed) + datas->algo.planeY * cos(-datas->algo.rotSpeed);
    return (0);
}

int    move_left(t_struct *datas)
{
    datas->algo.oldDirX = datas->algo.dirX;
    datas->algo.dirX =
    datas->algo.dirX * cos(datas->algo.rotSpeed) - datas->algo.dirY * sin(datas->algo.rotSpeed);
    datas->algo.dirY =
    datas->algo.oldDirX * sin(datas->algo.rotSpeed) + datas->algo.dirY * cos(datas->algo.rotSpeed);
    datas->algo.oldPlaneX = datas->algo.planeX;
    datas->algo.planeX =
    datas->algo.planeX * cos(datas->algo.rotSpeed) - datas->algo.planeY * sin(datas->algo.rotSpeed);
    datas->algo.planeY =
    datas->algo.oldPlaneX * sin(datas->algo.rotSpeed) + datas->algo.planeY * cos(datas->algo.rotSpeed);
    return (0);
}