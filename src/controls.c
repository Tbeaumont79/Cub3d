#include "../headers/cub3d.h"
#include "mlx.h"
void    quit(t_struct *datas)
{
	//ft_free(datas);

	system("leaks a.out");
    (void)datas;
    exit(1);
}

void    move_up(t_struct *datas)
{
    if (datas->game.map[(int)(datas->algo.posX + datas->algo.dirX * datas->algo.moveSpeed)]
    [(int)datas->algo.posY] != 1 && datas->game.map[(int)(datas->algo.posX + datas->algo.dirX * datas->algo.moveSpeed)]
    [(int)datas->algo.posY] != 2)
        datas->algo.posX += datas->algo.dirX * datas->algo.moveSpeed;
    if (datas->game.map[(int)datas->algo.posX]
    [(int)(datas->algo.posY + datas->algo.dirY * datas->algo.moveSpeed)] != 1
    && datas->game.map[(int)datas->algo.posX]
    [(int)(datas->algo.posY + datas->algo.dirY * datas->algo.moveSpeed)] != 2)
        datas->algo.posY += datas->algo.dirY * datas->algo.moveSpeed;
}

void    move_down(t_struct *datas)
{
        if (datas->game.map[(int)(datas->algo.posX - datas->algo.dirX * datas->algo.moveSpeed)]
    [(int)datas->algo.posY] != 1)
        datas->algo.posX -= datas->algo.dirX * datas->algo.moveSpeed;
    if (datas->game.map[(int)datas->algo.posX]
    [(int)(datas->algo.posY - datas->algo.dirY * datas->algo.moveSpeed)] != 1
    && datas->game.map[(int)datas->algo.posX]
    [(int)(datas->algo.posY - datas->algo.dirY * datas->algo.moveSpeed)] != 2)
        datas->algo.posY -= datas->algo.dirY * datas->algo.moveSpeed;
}

void    rotate_right(t_struct *datas)
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
}

void    rotate_left(t_struct *datas)
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
}

void    move_right(t_struct *datas)
{
    if (datas->game.map[(int)(datas->algo.posX + datas->algo.planeX
    * datas->algo.moveSpeed)][(int)(datas->algo.posY)] != 1
    && datas->game.map[(int)(datas->algo.posX + datas->algo.planeX
    * datas->algo.moveSpeed)][(int)(datas->algo.posY)] != 2)
        datas->algo.posX += datas->algo.planeX * datas->algo.moveSpeed;
    if (datas->game.map[(int)(datas->algo.posX)]
    [(int)(datas->algo.posY + datas->algo.planeY * datas->algo.moveSpeed)] != 1
    && datas->game.map[(int)(datas->algo.posX)]
    [(int)(datas->algo.posY + datas->algo.planeY * datas->algo.moveSpeed)] != 2)
        datas->algo.posY += datas->algo.planeY * datas->algo.moveSpeed;
}

void    move_left(t_struct *datas)
{
    if (datas->game.map[(int)(datas->algo.posX - datas->algo.planeX
    * datas->algo.moveSpeed)][(int)(datas->algo.posY)] != 1
    && datas->game.map[(int)(datas->algo.posX - datas->algo.planeX
    * datas->algo.moveSpeed)][(int)(datas->algo.posY)] != 2)
        datas->algo.posX -= datas->algo.planeX * datas->algo.moveSpeed;
    if (datas->game.map[(int)(datas->algo.posX)]
    [(int)(datas->algo.posY - datas->algo.planeY * datas->algo.moveSpeed)] != 1
    && datas->game.map[(int)(datas->algo.posX)]
    [(int)(datas->algo.posY - datas->algo.planeY * datas->algo.moveSpeed)] != 2)
        datas->algo.posY -= datas->algo.planeY * datas->algo.moveSpeed;
}