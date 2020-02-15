/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:59:31 by thbeaumo          #+#    #+#             */
/*   Updated: 2019/08/01 20:23:41 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (str);
	while (str[i])
	{
		if (to_find[j])
		{
			j = 0;
			while (to_find[j] == str[i + j])
			{
				if (to_find[j + 1] == '\0')
					return (str + i);
				j++;
			}
		}
		i++;
	}
	return (0);
}