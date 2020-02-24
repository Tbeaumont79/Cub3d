/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:13:19 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/23 16:15:43 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../Libft/libft.h"

double		define_spawn_deg(t_struct *datas)
{
	double deg;

	deg = datas->game.spaw_dir == 'O' ? M_PI_2 : 0;
	deg = datas->game.spaw_dir == 'E' ? -(M_PI_2) : deg;
	deg = datas->game.spaw_dir == 'N' ? 0 : deg;
	deg = datas->game.spaw_dir == 'S' ? -(M_PI) : deg;
	return (deg);
}

void		init_raycasting_var(t_struct *datas)
{
	double tmp_dirx;
	double old_planex;
	double deg;

	deg = define_spawn_deg(datas);
	datas->algo.dirx = -1;
	datas->algo.diry = 0;
	datas->algo.planex = 0;
	datas->algo.planey = 0.66;
	tmp_dirx = datas->algo.dirx;
	datas->algo.dirx =
	datas->algo.dirx * cos(deg) - datas->algo.diry * sin(deg);
	datas->algo.diry = tmp_dirx * sin(deg) + datas->algo.diry * cos(deg);
	old_planex = datas->algo.planex;
	datas->algo.planex =
	datas->algo.planex * cos(deg) - datas->algo.planey * sin(deg);
	datas->algo.planey = old_planex * sin(deg) + datas->algo.planey * cos(deg);
	datas->algo.movespeed = 0.05;
	datas->algo.rotspeed = 0.05;
}

void		init_raycasting_var_in_loop(t_struct *datas, int w, int h)
{
	(void)h;
	datas->algo.camerax = 2 * datas->algo.x / (double)w - 1;
	datas->algo.raydirx =
		datas->algo.dirx + datas->algo.planex * datas->algo.camerax;
	datas->algo.raydiry =
		datas->algo.diry + datas->algo.planey * datas->algo.camerax;
	datas->algo.mapx = (int)datas->algo.posx;
	datas->algo.mapy = (int)datas->algo.posy;
	datas->algo.deltadistx = (double)fabs(1 / datas->algo.raydirx);
	datas->algo.deltadisty = (double)fabs(1 / datas->algo.raydiry);
	datas->algo.hit = 0;
}
