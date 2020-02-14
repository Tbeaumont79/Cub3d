#include "../headers/cub3d.h"
#include "mlx.h"

void    ft_get_texture(t_struct *datas)
{
    int i;

    i = -1;
    while (++i < 4)
    {
        datas->tex[i].tex_img = 
        mlx_xpm_to_image(datas->img.ptr, &datas->tex[i].name,
        datas->tex[i].t_w, datas->tex[i].t_h);
        datas->tex[i].datas = 
        (int *)mlx_get_data_addr(datas->tex[i].tex_img, &datas->tex[i].bpp,
        &datas->tex[i].size_line, &datas->tex[i].endian);
    }
}