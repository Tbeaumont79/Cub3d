#include "../headers/cub3d.h"
#include "mlx.h"

void    choose_tex(t_struct *datas, int *color, int val)
{
    int i;

    i = -1;
    while (++i < 4)
        if (i == datas->algo.side)
            break ;
    if (datas->algo.side == i && i >= 0)
    {
        datas->algo.texY[i] = 
        ((val * datas->tex[i].t_h) / datas->algo.lineHeight) / 256;
        *color = datas->tex[i].datas[(datas->tex[i].t_h * datas->algo.texY[i])
        + datas->algo.texX[i]];
    }
}

void    init_algo_tex(t_struct *datas)
{
    int i;

    i = -1;
    while (++i < 4)
    {
        datas->algo.texX[i] = (int)(datas->algo.wallX * (double)(datas->tex[i].t_w));
        datas->algo.texX[i] = datas->tex[i].t_w - datas->algo.texX[i] - 1;
    }
}

void    ft_get_texture(t_struct *datas)
{
    int i;

    i = -1;
    while (++i < 4)
    {
        datas->tex[i].tex_img = 
        mlx_xpm_to_image(datas->img.ptr, datas->tex[i].name,
        &datas->tex[i].t_w, &datas->tex[i].t_h);
        datas->tex[i].datas = 
        (int *)mlx_get_data_addr(datas->tex[i].tex_img, &datas->tex[i].bpp,
        &datas->tex[i].size_line, &datas->tex[i].endian);
    }
}