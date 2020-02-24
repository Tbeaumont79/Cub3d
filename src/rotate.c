/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:18:27 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/23 16:19:14 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../headers/mlx.h"

void	rotate_right(t_struct *datas)
{
	datas->algo.oldirx = datas->algo.dirx;
	datas->algo.dirx =
		datas->algo.dirx * cos(-datas->algo.rotspeed) - datas->algo.diry *
		sin(-datas->algo.rotspeed);
	datas->algo.diry =
		datas->algo.oldirx * sin(-datas->algo.rotspeed) + datas->algo.diry *
		cos(-datas->algo.rotspeed);
	datas->algo.oldplanex = datas->algo.planex;
	datas->algo.planex =
		datas->algo.planex * cos(-datas->algo.rotspeed) - datas->algo.planey *
		sin(-datas->algo.rotspeed);
	datas->algo.planey =
		datas->algo.oldplanex * sin(-datas->algo.rotspeed) + datas->algo.planey
		* cos(-datas->algo.rotspeed);
}

void	rotate_left(t_struct *datas)
{
	datas->algo.oldirx = datas->algo.dirx;
	datas->algo.dirx =
		datas->algo.dirx * cos(datas->algo.rotspeed) - datas->algo.diry *
		sin(datas->algo.rotspeed);
	datas->algo.diry =
		datas->algo.oldirx * sin(datas->algo.rotspeed) + datas->algo.diry *
		cos(datas->algo.rotspeed);
	datas->algo.oldplanex = datas->algo.planex;
	datas->algo.planex =
		datas->algo.planex * cos(datas->algo.rotspeed) - datas->algo.planey *
		sin(datas->algo.rotspeed);
	datas->algo.planey =
		datas->algo.oldplanex * sin(datas->algo.rotspeed) + datas->algo.planey *
		cos(datas->algo.rotspeed);
}
