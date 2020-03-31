#include "../headers/cub3d.h"
#include "../headers/mlx.h"
#include "../Libft/libft.h"

void    init_player(t_struct *datas)
{
	static int booleane = 0;

	if (booleane == 0)
	{
		datas->player.img = mlx_xpm_file_to_image(datas->img.ptr, "./textures/sword.xpm",
		&datas->player.tex_w, &datas->player.tex_h);
		datas->player.data = (int *)mlx_get_data_addr(datas->player.img, 
		&datas->player.bpp, &datas->player.size_line, &datas->player.endian);
        booleane = 1;
	}
}

void    draw_player(t_struct *datas, int x, int y)
{
    int i;
    int j;
    int texx;
    int texy;
    int color;

    i = 0;
    while (i < datas->game.w_w / 5)
    {
        texx = (int)(i * datas->player.tex_w / (datas->game.w_w / 5));
        j = 0;
        while (j < datas->game.w_h / (5 / 2))
        {
            texy = (int)(j * datas->player.tex_h / (datas->game.w_h / (5 / 2)));
            color = datas->player.data[(datas->player.tex_w * texy) + texx];
            if (color != 16777215)
                datas->player.data[(datas->game.w_w * (y + j)) + (x + i)] = color;
            j++;
        }
        i++;
    }
}
