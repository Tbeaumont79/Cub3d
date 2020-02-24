/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprit_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:26:34 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/24 13:20:15 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../headers/mlx.h"

void	define_sprit_texture(t_struct *datas, int j)
{
	if (datas->game.map[datas->sprit[j].posx][datas->sprit[j].posy] == 2
			&& datas->game.map[datas->sprit[j].posx][datas->sprit[j].posy] != 3)
		datas->algo.s_name = datas->game.sprit_tex;
	if (datas->game.map[datas->sprit[j].posx][datas->sprit[j].posy] == 3
			&& datas->game.map[datas->sprit[j].posx][datas->sprit[j].posy] != 2)
		datas->algo.s_name = datas->game.sprit_tex2;
}

int		define_size(t_struct *datas)
{
	int size;

	size = datas->game.num_sprit == 0 && datas->game.sprit_light > 0 ?
		datas->game.sprit_light : 0;
	size = datas->game.num_sprit > 0 && datas->game.sprit_light == 0 ?
		datas->game.num_sprit : size;
	size = datas->game.num_sprit >= 0 && datas->game.sprit_light >= 0 ?
		datas->game.num_sprit + datas->game.sprit_light : size;
	return (size);
}
