/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flortexture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:30:48 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/23 12:10:28 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "mlx.h"

void	define_florwallxandy(t_struct *datas)
{
	if (datas->algo.side == 1 && datas->algo.raydirx > 0)
	{
		datas->algo.floorxwall = datas->algo.mapx;
		datas->algo.floorywall = datas->algo.mapy + datas->algo.wallx;
	}
	if (datas->algo.side == 0 && datas->algo.raydirx < 0)
	{
		datas->algo.floorxwall = datas->algo.mapx + 1.0;
		datas->algo.floorywall = datas->algo.mapy + datas->algo.wallx;
	}
	if (datas->algo.side == 3 && datas->algo.raydiry > 0)
	{
		datas->algo.floorxwall = datas->algo.mapx + datas->algo.wallx;
		datas->algo.floorywall = datas->algo.mapy;
	}
	if (datas->algo.side == 2 && datas->algo.raydiry < 0)
	{
		datas->algo.floorxwall = datas->algo.mapx + datas->algo.wallx;
		datas->algo.floorywall = datas->algo.mapy + 1.0;
	}
}

void	handle_flor_cal(t_struct *datas, int y)
{
	datas->algo.currentdist = datas->game.w_h / (2.0 * y - datas->game.w_h);
	datas->algo.weight = (datas->algo.currentdist - datas->algo.distplayer) /
		(datas->algo.distwall - datas->algo.distplayer);
	datas->algo.currentfloorx = datas->algo.weight * datas->algo.floorxwall +
		(1.0 - datas->algo.weight) * datas->algo.posx;
	datas->algo.currentfloory = datas->algo.weight * datas->algo.floorywall +
		(1.0 - datas->algo.weight) * datas->algo.posy;
	datas->algo.floortexx = (int)(datas->algo.currentfloorx * datas->tex[4].t_w)
	% datas->tex[4].t_w;
	datas->algo.floortexy = (int)(datas->algo.currentfloory * datas->tex[4].t_h)
		% datas->tex[4].t_h;
	datas->game.flor_color = datas->tex[4].datas[datas->tex[4].t_w *
		datas->algo.floortexy + datas->algo.floortexx];
	datas->img.datas[(datas->game.w_w * y) + datas->algo.x] =
		datas->game.flor_color;
}

void	draw_flor_text(t_struct *datas)
{
	int y;

	define_florwallxandy(datas);
	datas->algo.distwall = datas->algo.perpwalldist;
	datas->algo.distplayer = 0.0;
	if (datas->algo.drawend < 0)
		datas->algo.drawend = datas->game.w_h;
	y = datas->algo.drawend;
	while (++y < datas->game.w_h)
		handle_flor_cal(datas, y);
}
