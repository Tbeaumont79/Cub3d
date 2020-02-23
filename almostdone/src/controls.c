/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:51:28 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/23 16:19:15 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../headers/mlx.h"

void	quit(t_struct *datas)
{
	(void)datas;
	exit(1);
}

void	move_up(t_struct *datas)
{
	if (datas->game.map[(int)
		(datas->algo.posx + datas->algo.dirx * datas->algo.movespeed)]
			[(int)datas->algo.posy] != 1 && datas->game.map[(int)
			(datas->algo.posx + datas->algo.dirx * datas->algo.movespeed)]
			[(int)datas->algo.posy] != 2)
		datas->algo.posx += datas->algo.dirx * datas->algo.movespeed;
	if (datas->game.map[(int)datas->algo.posx]
			[(int)(datas->algo.posy + datas->algo.diry * datas->algo.movespeed)]
			!= 1
			&& datas->game.map[(int)datas->algo.posx]
			[(int)(datas->algo.posy + datas->algo.diry * datas->algo.movespeed)]
			!= 2)
		datas->algo.posy += datas->algo.diry * datas->algo.movespeed;
}

void	move_down(t_struct *datas)
{
	if (datas->game.map[(int)(datas->algo.posx - datas->algo.dirx *
			datas->algo.movespeed)]
			[(int)datas->algo.posy] != 1)
		datas->algo.posx -= datas->algo.dirx * datas->algo.movespeed;
	if (datas->game.map[(int)datas->algo.posx]
			[(int)(datas->algo.posy - datas->algo.diry * datas->algo.movespeed)]
			!= 1
			&& datas->game.map[(int)datas->algo.posx]
			[(int)(datas->algo.posy - datas->algo.diry * datas->algo.movespeed)]
			!= 2)
		datas->algo.posy -= datas->algo.diry * datas->algo.movespeed;
}

void	move_right(t_struct *datas)
{
	if (datas->game.map[(int)(datas->algo.posx + datas->algo.planex
				* datas->algo.movespeed)][(int)(datas->algo.posy)] != 1
			&& datas->game.map[(int)(datas->algo.posx + datas->algo.planex
				* datas->algo.movespeed)][(int)(datas->algo.posy)] != 2)
		datas->algo.posx += datas->algo.planex * datas->algo.movespeed;
	if (datas->game.map[(int)(datas->algo.posx)]
			[(int)(datas->algo.posy + datas->algo.planey *
				datas->algo.movespeed)] != 1
			&& datas->game.map[(int)(datas->algo.posx)]
			[(int)(datas->algo.posy + datas->algo.planey *
				datas->algo.movespeed)] != 2)
		datas->algo.posy += datas->algo.planey * datas->algo.movespeed;
}

void	move_left(t_struct *datas)
{
	if (datas->game.map[(int)(datas->algo.posx - datas->algo.planex
				* datas->algo.movespeed)][(int)(datas->algo.posy)] != 1
			&& datas->game.map[(int)(datas->algo.posx - datas->algo.planex
				* datas->algo.movespeed)][(int)(datas->algo.posy)] != 2)
		datas->algo.posx -= datas->algo.planex * datas->algo.movespeed;
	if (datas->game.map[(int)(datas->algo.posx)]
			[(int)(datas->algo.posy - datas->algo.planey *
				datas->algo.movespeed)] != 1
			&& datas->game.map[(int)(datas->algo.posx)]
			[(int)(datas->algo.posy - datas->algo.planey *
				datas->algo.movespeed)] != 2)
		datas->algo.posy -= datas->algo.planey * datas->algo.movespeed;
}
