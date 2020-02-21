#include "mlx.h"
#include "../headers/cub3d.h"
#include "../Libft/libft.h"

void int_char(unsigned char *headerbmp, unsigned int val)
{
    unsigned int *ptr;

    ptr = (unsigned int *)headerbmp;
    *ptr = val;
}

int write_header(t_struct *datas, int fd, int fsize)
{
    int tmp;
    int i;
    unsigned char headerbmp[54];

    ft_bzero(headerbmp, 54);
    headerbmp[0] = (unsigned char)'B';
    headerbmp[1] = (unsigned char)'M';
    int_char(headerbmp + 2, fsize);
    headerbmp[10] = (unsigned char)54;
    headerbmp[14] = (unsigned char)40;
    tmp = datas->game.w_w;
    int_char(headerbmp + 18, tmp);
    tmp = -datas->game.w_h;
    int_char(headerbmp + 22, tmp);
    headerbmp[26] = (unsigned char)1;
    headerbmp[28] = (unsigned char)24;
    write(fd, headerbmp, 54);
    return (1);
}

int     get_color_bmp(t_struct *datas, int i, int j)
{
    int c_to_rgb;
    int color;

    color = datas->img.datas[datas->game.w_w * j + i];
    c_to_rgb =
    (color & 0xFF) | (color & 0x00FF) | (color & 0x0000FF);
    return (c_to_rgb);
}

int write_data(int file, t_struct *datas, unsigned int gap)
{
    static unsigned char zero[3] = {0, 0, 0};
    int i;
    int j;
    int color;

    i = -1;
    while (++i < datas->game.w_h)
    {
        j = -1;
        while (++j < datas->game.w_w)
        {
            color = get_color_bmp(datas, i, j);
            if (write(file, &color,3) == -1)
                return (-1);
        }
        if (gap > 0 && write(file, &zero, gap) == -1)
            return (-1);
    }
    return (0);
}

int     ft_screenshot(t_struct *datas)
{
    int fd;
    unsigned int pibpr;
    unsigned int pabpr;
    unsigned int fsize;

    ft_raycasting(datas);
    pibpr = datas->game.w_w * 3;
    pabpr = (4 - (pibpr % 4)) % 4;
    fsize = 54
        + (pibpr + pabpr) * datas->game.w_h;
    if ((fd = open("screen.bmp", O_WRONLY
    | O_CREAT | O_TRUNC | S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) == -1)
        return (-1);
    if ((write_header(datas, fd, fsize)) == -1)
        return (-1);
    if ((write_data(fd, datas, pabpr)))
        return (0);
    close(fd);
    free(datas);
    return (1);
}