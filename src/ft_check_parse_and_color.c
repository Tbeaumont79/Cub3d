/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parse_and_color.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:14:54 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/24 16:59:58 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int		exite(int key, void *datas)
{
	(void)key;
	(void)datas;
	exit(1);
	return (0);
}

int		check_all(t_struct *datas)
{
	if (datas->game.num_spawn == 0)
		return (ft_error("there is no spawn on the map !\n"));
	if (datas->game.num_spawn > 1)
		return (ft_error("there is too much spawn !\n"));
	if ((datas->game.num_sprit > 0 && datas->game.sprit_tex == NULL)
			|| (datas->game.sprit_light > 0 && datas->game.sprit_tex2 == NULL))
		return (ft_error("invalide sprit path !\n"));
	if (datas->game.flor_color == 0)
		return (ft_error("the flor has no color set !\n"));
	if (datas->game.rof_color == 0)
		return (ft_error("the roof has no color set !\n"));
	if (datas->game.w_w == 0)
		return (ft_error("the windows width is not set ! \n"));
	if (datas->game.w_h == 0)
		return (ft_error("the windows heigth is not set ! \n"));
	if (datas->game.w_w > 2560 && datas->game.w_h > 1440)
	{
		datas->game.w_w = 2560;
		datas->game.w_h = 1440;
	}
	return (0);
}
