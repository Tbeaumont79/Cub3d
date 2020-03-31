/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:23:04 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/23 14:16:26 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../headers/mlx.h"
#include "../Libft/libft.h"

void	init_structure(t_struct *datas)
{
	datas->img.ptr = mlx_init();
	datas->img.win =
	mlx_new_window(datas->img.ptr, datas->game.w_w, datas->game.w_h, "cub3d");
}

void	init_img(t_struct *datas)
{
	datas->img.img =
		mlx_new_image(datas->img.ptr, datas->game.w_w, datas->game.w_h);
	datas->img.datas = (int *)mlx_get_data_addr(datas->img.img,
			&(datas->img.bpp), &(datas->img.size_line), &(datas->img.endian));
}

void	render(t_struct *datas)
{
	free(datas->algo.zbuff);
	//init_player(datas);
	mlx_put_image_to_window(datas->img.ptr, datas->img.win,
	datas->img.img, 0, 0);
	mlx_destroy_image(datas->img.ptr, datas->img.img);
}

void	init_basic_var(t_struct *datas)
{
	datas->game.m_h = 0;
	datas->game.m_w = 0;
	datas->game.flor_color = 0;
	datas->game.num_spawn = 0;
	datas->game.sprit_light = 0;
	datas->game.rof_color = 0;
	datas->game.m_parsed = 0;
	datas->game.m_line = 0;
	datas->game.m_space = 0;
	datas->game.num_tex = 0;
	datas->algo.ret = 0;
}

int		main(int argc, char **argv)
{
	t_struct *datas;

	(void)argc;
	if (!(datas = (t_struct *)malloc(sizeof(t_struct))))
		return (0);
	init_basic_var(datas);
	if ((ft_read_file(argv[1], datas)) == -1)
		return (-1);
	init_structure(datas);
	if ((check_all(datas) == -1))
		return (-1);
	if ((ft_get_texture(datas)) == -1)
		return (-1);
	init_raycasting_var(datas);
	mlx_hook(datas->img.win, 17, 0L, exite, datas);
	mlx_hook(datas->img.win, 2, (1L << 0), keypress, datas);
	mlx_hook(datas->img.win, 3, (1L << 1), keyunpress, datas);
	mlx_loop_hook(datas->img.ptr, keyparsing, datas);
	ft_raycasting(datas);
	if (argc - 1 == 2)
		if (ft_strstr(argv[2], "--save"))
			ft_screenshot(datas);
	mlx_loop(datas->img.ptr);
	return (0);
}
