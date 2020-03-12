/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:27:04 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/03/12 21:49:06 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../headers/mlx.h"
#include "../Libft/libft.h"

int		add_tex_path(t_struct *datas, char *s, int i)
{
	int j;

	j = 0;
	skip_char(&s, ' ');
	if (*s)
	{
		datas->tex[i].name = ft_strdup(s);
		datas->game.num_tex++;
		datas->game.m_parsed++;
	}
	return (0);
}

void	choose_tex(t_struct *datas, int *color, int val)
{
	int i;

	i = -1;
	while (++i < 4)
		if (i == datas->algo.side)
			break ;
	if (datas->algo.side == i && i >= 0)
	{
		datas->algo.texy[i] =
			((val * datas->tex[i].t_h) / datas->algo.lineheight) / 256;
		*color = datas->tex[i].datas[(datas->tex[i].t_w * datas->algo.texy[i])
		+ datas->algo.texx[i]];
	}
}

void	init_algo_tex(t_struct *datas)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		datas->algo.texx[i] = (int)(datas->algo.wallx *
		(double)(datas->tex[i].t_w));
		datas->algo.texx[i] = datas->tex[i].t_w - datas->algo.texx[i] - 1;
	}
}

int		ft_get_texture(t_struct *datas)
{
	int i;

	i = -1;
	while (++i < datas->game.num_tex)
	{
		if (!(datas->tex[i].tex_img =
					mlx_xpm_file_to_image(datas->img.ptr, datas->tex[i].name,
						&datas->tex[i].t_w, &datas->tex[i].t_h)))
			return (ft_error("error texture !\n"));
		datas->tex[i].datas =
			(int *)mlx_get_data_addr(datas->tex[i].tex_img, &datas->tex[i].bpp,
					&datas->tex[i].size_line, &datas->tex[i].endian);
	}
	return (0);
}
