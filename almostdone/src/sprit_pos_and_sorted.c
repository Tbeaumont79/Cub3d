/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprit_pos_and_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:13:01 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/23 14:17:07 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int		add_sprit_pos(t_struct *datas, int i, int j, int num)
{
	datas->sprit[num].posx = i;
	datas->sprit[num].posy = j;
	num++;
	return (num);
}

void	get_sprit_pos(t_struct *datas)
{
	int i;
	int j;
	int num;

	num = 0;
	i = -1;
	while (++i < datas->game.m_h)
	{
		j = -1;
		while (++j < datas->game.m_w)
		{
			if (datas->game.map[i][j] == 2)
				num = add_sprit_pos(datas, i, j, num);
			else if (datas->game.map[i][j] == 3)
				num = add_sprit_pos(datas, i, j, num);
		}
	}
}

int		ft_swap_values(int i, int val, t_struct *datas, int swap)
{
	t_sprit tmp;

	tmp = datas->sprit[i];
	datas->sprit[i] = datas->sprit[val];
	datas->sprit[val] = tmp;
	swap = 1;
	return (swap);
}

int		sorted_sprite(t_struct *datas)
{
	int i;
	int n_s;
	int swap;

	swap = 0;
	n_s = datas->game.num_sprit;
	while (swap || n_s > 1)
	{
		n_s = (n_s * 10) / 13;
		if (n_s == 9 || n_s == 10)
			n_s = 11;
		n_s = n_s < 1 ? 1 : n_s;
		i = 0;
		swap = 0;
		while (i < datas->game.num_sprit - n_s)
		{
			if (datas->sprit[i].sprite_distance <
				datas->sprit[i + n_s].sprite_distance)
				swap = ft_swap_values(i, i + n_s, datas, swap);
			i++;
		}
	}
	return (0);
}
