/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:04:06 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/23 12:06:18 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../headers/cub3d.h"
#include "../Libft/libft.h"

int		write_bmp(t_struct *datas, int fd, int lsize)
{
	write(fd, "BM", 2);
	w_i(fd, 54 + (3 * (datas->game.w_w + lsize) * datas->game.w_h % 4));
	w_i(fd, 0);
	w_i(fd, 54);
	w_i(fd, 40);
	w_i(fd, datas->game.w_w);
	w_i(fd, datas->game.w_h);
	w_h_i(fd, 1);
	w_h_i(fd, 24);
	w_i(fd, 0);
	w_i(fd, 0);
	w_i(fd, 6400);
	w_i(fd, 6400);
	w_i(fd, 0);
	w_i(fd, 0);
	return (0);
}

int		write_data(int file, t_struct *datas)
{
	int				i;
	int				j;
	unsigned int	color;
	int				r;

	r = (datas->game.w_w * 3) % 4;
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

int		ft_screenshot(t_struct *datas)
{
	int fd;
	int lsize;

	lsize = (4 - (datas->game.w_w * 3) % 4) % 4;
	if (!(fd = open("screen.bmp", O_WRONLY
					| O_CREAT, 0666)))
		return (0);
	write_bmp(datas, fd, lsize);
	write_data(fd, datas);
	close(fd);
	return (0);
}
