/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:16:39 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/23 16:14:33 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../Libft/libft.h"

void		check_raycasting(t_struct *datas)
{
	if (datas->algo.raydirx < 0)
	{
		datas->algo.stepx = -1;
		datas->algo.sidedistx =
			(datas->algo.posx - datas->algo.mapx) * datas->algo.deltadistx;
	}
	else
	{
		datas->algo.stepx = 1;
		datas->algo.sidedistx =
		(datas->algo.mapx + 1.0 - datas->algo.posx) * datas->algo.deltadistx;
	}
	if (datas->algo.raydiry < 0)
	{
		datas->algo.stepy = -1;
		datas->algo.sidedisty =
			(datas->algo.posy - datas->algo.mapy) * datas->algo.deltadisty;
	}
	else
	{
		datas->algo.stepy = 1;
		datas->algo.sidedisty =
		(datas->algo.mapy + 1.0 - datas->algo.posy) * datas->algo.deltadisty;
	}
}

void		check_hit(t_struct *datas)
{
	while (datas->algo.hit == 0)
	{
		if (datas->algo.sidedistx < datas->algo.sidedisty)
		{
			datas->algo.side = datas->algo.raydirx < 0 ? 0 : 1;
			datas->algo.sidedistx += datas->algo.deltadistx;
			datas->algo.mapx += datas->algo.stepx;
		}
		else
		{
			datas->algo.side = datas->algo.raydiry < 0 ? 2 : 3;
			datas->algo.sidedisty += datas->algo.deltadisty;
			datas->algo.mapy += datas->algo.stepy;
		}
		if (datas->game.map[datas->algo.mapx][datas->algo.mapy] == 1)
			datas->algo.hit = 1;
	}
}

void		init_calcul_for_draw_wall(t_struct *datas, int w, int h)
{
	(void)w;
	datas->algo.perpwalldist = datas->algo.side == 0 || datas->algo.side == 1 ?
		(datas->algo.mapx - datas->algo.posx + (1 - datas->algo.stepx) / 2)
		/ datas->algo.raydirx : (datas->algo.mapy - datas->algo.posy +
				(1 - datas->algo.stepy) / 2) / datas->algo.raydiry;
	datas->algo.lineheight = (int)(h / datas->algo.perpwalldist);
	datas->algo.drawstart = -datas->algo.lineheight / 2 + h / 2;
	if (datas->algo.drawstart < 0)
		datas->algo.drawstart = 0;
	datas->algo.drawend = datas->algo.lineheight / 2 + h / 2;
	if (datas->algo.drawend >= h)
		datas->algo.drawend = h - 1;
	datas->algo.wallx = datas->algo.side == 0 || datas->algo.side == 1 ?
		datas->algo.posy + datas->algo.perpwalldist * datas->algo.raydiry :
		datas->algo.posx + datas->algo.perpwalldist * datas->algo.raydirx;
	datas->algo.wallx -= floor((datas->algo.wallx));
}

int			ft_raycasting(t_struct *datas)
{
	int h;
	int w;

	w = datas->game.w_w;
	h = datas->game.w_h;
	datas->game.check_sprit = 0;
	datas->algo.x = -1;
	if (!(datas->algo.zbuff = malloc(sizeof(double) * datas->game.w_w)))
		return (ft_error("malloc !\n"));
	init_img(datas);
	while (++datas->algo.x < w)
	{
		init_raycasting_var_in_loop(datas, w, h);
		check_raycasting(datas);
		check_hit(datas);
		init_calcul_for_draw_wall(datas, w, h);
		draw(datas);
		datas->algo.zbuff[datas->algo.x] = datas->algo.perpwalldist;
	}
	if (datas->game.num_sprit > 0)
		if ((handle_sprit(datas)) == -1)
			return (ft_error("sprit !"));
	render(datas);
	return (0);
}
