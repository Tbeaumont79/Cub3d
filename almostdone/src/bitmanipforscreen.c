/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmanipforscreen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:06:40 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/23 12:07:06 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../Libft/libft.h"

void	w_h_i(int fd, int val)
{
	char ptr;

	ptr = val & 0xff;
	write(fd, &ptr, 1);
	ptr = (val >> 8) & 0xff;
	write(fd, &ptr, 1);
}

void	w_i(int fd, int val)
{
	w_h_i(fd, val);
	w_h_i(fd, val >> 16);
}

void	w_c(int fd, int color)
{
	char ptr;

	w_h_i(fd, color);
	ptr = color >> 16 & 0xff;
	write(fd, &ptr, 1);
}

void	w_end(int fd, int val)
{
	while (val)
	{
		write(fd, "\0", 1);
		val--;
	}
}
