#include "mlx.h"
#include "../headers/cub3d.h"
#include "../Libft/libft.h"


void w_h_i(int fd, int val)
{
    char ptr;

    ptr = val & 0xff;
    write(fd, &ptr, 1);
    ptr = (val >> 8) & 0xff;
    write(fd, &ptr, 1);
}

void w_i(int fd, int val)
{
    w_h_i(fd, val);
    w_h_i(fd, val >> 16);
}

void w_c(int fd, int color)
{
    char ptr;

    w_h_i(fd, color);
    ptr = color >> 16 & 0xff;
    write(fd, &ptr, 1);
}

void w_end(int fd, int val)
{
    while (val--)
        write(fd, "\0", 1);
}

int write_bmp(t_struct *datas, int fd, int lsize)
{
    write(fd, "BM", 2);
    w_i(fd, 54 + lsize * datas->game.w_h);
    w_i(fd, 0);
    w_i(fd, 54);
    w_i(fd, 40);
    w_i(fd, datas->game.w_w);
    w_i(fd, datas->game.w_h);
    w_i(fd, 1);
    w_i(fd, 24);
    w_i(fd, 0);
    w_i(fd, 0);
    w_i(fd, 6400);
    w_i(fd, 6400);
    w_i(fd, 0);
    w_i(fd, 0);
    return (0);
}

int write_data(int file, t_struct *datas)
{
    int i;
    int j;
    unsigned int color;
    int r;

    r = datas->game.w_w * 3 % 4;
    i = datas->game.w_h - 1;
    while (i >= 0)
    {
        j = -1;
        while (++j < datas->game.w_w)
        {
            color = datas->img.datas[(datas->game.w_w * i) + j];
            w_c(file, color);
            if (r)
                w_end(file, 4 - r);
        }
        i--;
    }
    return (0);
}

int     ft_screenshot(t_struct *datas)
{
    int fd;
    int lsize;

    lsize = datas->game.w_w * 3;
    lsize += lsize % 4 ? 4 - lsize % 4 : lsize;
    lsize += 4 - lsize % 4;
    if (!(fd = open("screen.bmp", O_WRONLY
    | O_CREAT, 0666)))
        return (0);
    write_bmp(datas, fd, lsize);
    write_data(fd, datas);
    close(fd);
    return (1);
}