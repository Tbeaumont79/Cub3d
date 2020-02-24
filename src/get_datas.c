/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_datas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:29:59 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/23 16:08:40 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../Libft/libft.h"

void	skip_char(char **s, int c)
{
	while (**s == c)
		(*s)++;
}

int		ft_fill_s(t_struct *datas, char *str)
{
	if (*str == '1')
	{
		if (datas->game.m_parsed < 5)
			return (ft_error("map not at the end of file !"));
		datas->algo.tmp = gnl_strjoin(datas->algo.s, str);
		free(datas->algo.s);
		datas->algo.s = datas->algo.tmp;
		datas->algo.tmp2 = gnl_strjoin(datas->algo.s, "\n");
		free(datas->algo.s);
		datas->algo.s = datas->algo.tmp2;
		datas->game.m_line++;
	}
	return (0);
}

int		add_sprit_path(t_struct *datas, char *s)
{
	skip_char(&s, ' ');
	if (*s == 'X')
	{
		s++;
		skip_char(&s, ' ');
		datas->game.sprit_tex2 = ft_strdup(s);
		datas->game.m_parsed++;
	}
	if (*s == 'S' && *(s + 1) != 'O')
	{
		s++;
		skip_char(&s, ' ');
		datas->game.sprit_tex = ft_strdup(s);
		datas->game.m_parsed++;
	}
	return (0);
}

int		add_reso(t_struct *datas, char *s)
{
	skip_char(&s, ' ');
	if (*s == 'R')
	{
		s++;
		datas->game.w_w = ft_atoi((const char **)&s);
		datas->game.w_h = ft_atoi((const char **)&s);
		datas->game.m_parsed++;
	}
	return (0);
}
