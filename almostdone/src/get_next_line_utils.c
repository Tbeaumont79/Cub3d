/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:58:07 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/23 12:18:32 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../Libft/libft.h"

char	*gnl_strjoin(char const *s1, char *s2)
{
	size_t		i;
	size_t		j;
	size_t		s1len;
	size_t		s2len;
	char		*tab;

	s1len = s1 ? ft_strlen((char *)s1) : 0;
	s2len = s2 ? ft_strlen((char *)s2) : 0;
	if (!(tab = malloc(sizeof(char) * (s1len + s2len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < s1len)
	{
		tab[i] = s1[i];
		i++;
	}
	while (j < s2len)
	{
		tab[i + j] = s2[j];
		j++;
	}
	tab[i + j] = '\0';
	return (tab);
}
