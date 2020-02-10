#include "mlx.h"
#define win_width 1000
#define heigth_width 1000
#include <unistd.h>
#include <stdlib.h>
void ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        ft_putchar('-');
        ft_putchar('2');
        ft_putnbr(147483648);
    }
    if (nb < 0)
        ft_putchar('-');
    if (nb > 0)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + 48);
}

int key_press(int key_value, void *param)
{
    ft_putnbr(key_value);
    if (key_value == 53)
        exit(EXIT_SUCCESS);
    return (0);
}

int main()
{
    void *ptr;
    void *win;
    int *datas;
    void *img;
    int bpp;
    int size_line;
    int endian;
    int x = -1;
    int y = -1;

    ptr = mlx_init();
    win = mlx_new_window(ptr, win_width, heigth_width, "Title");
    img = mlx_new_image(ptr, win_width, heigth_width);
    datas = (int *)mlx_get_data_addr(img, &bpp, &size_line, &endian);
    while (++x < heigth_width / 2)
    {
        y = -1;
        while (++y < win_width)
            datas[x * win_width + y] = 0x000099;
    }
    while (++x < heigth_width)
    {
        y = -1;
        while (++y < win_width)
            datas[x * win_width + y] = 0xFFFFFF;
    }
    mlx_put_image_to_window(ptr, win, img, 0, 0);
    mlx_key_hook(win, key_press, (void *)0);
    mlx_loop(ptr);
    return (0);
}
