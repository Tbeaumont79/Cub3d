#include "../headers/cub3d.h"
#include "mlx.h"
//faire un tableau de structure ? 
void    ft_get_texture(t_struct *datas)
{
    int i;

    i = -1;
    while (++i < 4)
    {
        datas->tex.tex[i] = 
        mlx_xpm_to_image(datas->img.ptr, &datas->tex.name,
        datas->tex.t_w, datas->tex.t_h);
        datas->tex.datas = 
        mlx_get_data_addr(datas->tex.t_img, &datas->tex.bpp,
        &datas->tex.size_line, &datas->tex.endian);
    }
}