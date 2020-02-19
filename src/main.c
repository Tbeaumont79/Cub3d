#include "../headers/cub3d.h"
#include "mlx.h"

void init_structure(t_struct *datas)
{
    datas->img.ptr = mlx_init();
    datas->img.win = 
    mlx_new_window(datas->img.ptr, datas->game.w_w, datas->game.w_h, "cub3d");
}

void init_img(t_struct *datas)
{
	datas->img.img =
	mlx_new_image(datas->img.ptr, datas->game.w_w, datas->game.w_h);
	datas->img.datas = (int *)mlx_get_data_addr(datas->img.img, &(datas->img.bpp)
    , &(datas->img.size_line), &(datas->img.endian));
}

void	render(t_struct *datas)
{
	free(datas->algo.zbuff);
    mlx_put_image_to_window(datas->img.ptr, datas->img.win, datas->img.img, 0, 0);
	mlx_destroy_image(datas->img.ptr, datas->img.img);
}

void	init_basic_var(t_struct *datas)
{
	datas->game.m_h = 0;
	datas->game.m_w = 0;
	datas->game.flor_color = 0;
	datas->game.num_spawn = 0;
	datas->game.rof_color = 0;
    datas->game.m_parsed = 0;
	datas->game.m_line = 0;
	datas->game.m_space = 0;
}

int main(int argc, char **argv)
{
    (void)argc;
    t_struct *datas;

    if (!(datas = (t_struct *)malloc(sizeof(t_struct))))
        return (0);
	init_basic_var(datas);
	if ((ft_read_file(argv[1], datas)) == -1)
		return (-1);
    init_structure(datas);
	if ((ft_get_texture(datas)) == -1)
		return (-1);
    init_raycasting_var(datas);
	mlx_hook(datas->img.win, 2, (1L << 0), keypress, datas);
	mlx_hook(datas->img.win, 3, (1L << 1), keyunpress, datas);
	mlx_loop_hook(datas->img.ptr, keyparsing, datas);
	ft_raycasting(datas);
    mlx_loop(datas->img.ptr);
    return (0);
}