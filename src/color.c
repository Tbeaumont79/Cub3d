/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:20:01 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/24 15:27:06 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../Libft/libft.h"

unsigned long	ft_dec_to_hexa(int r, int g, int b)
{
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int				init_color(char *s)
{
	int val;
	int r;
	int g;
	int b;

	r = 0;
	g = 0;
	b = 0;
	val = 0;
	r = ft_atoi((const char **)&s);
	skip_char(&s, ',');
	g = ft_atoi((const char **)&s);
	skip_char(&s, ',');
	b = ft_atoi((const char **)&s);
	val = ft_dec_to_hexa(r, g, b);
	return (val);
}

int				ft_get_color(t_struct *datas, char *s)
{
	skip_char(&s, ' ');
	if (*s == 'F')
	{
		s++;
		datas->game.flor_color = init_color(s);
		datas->game.m_parsed++;
	}
	else if (*s == 'C')
	{
		s++;
		datas->game.rof_color = init_color(s);
		datas->game.m_parsed++;
	}
	return (0);
}
