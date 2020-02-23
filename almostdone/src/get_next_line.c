/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:55:42 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/01/09 10:40:21 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../Libft/libft.h"

static int		ft_cutline(char **s, char **line)
{
	int		i;
	int		ret;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (*s[i])
	{
		while ((*s)[i] != '\n' && (*s)[i])
			i++;
		ret = ((*s)[i] == '\n') ? 1 : 0;
		if (!(*line = ft_substr(*s, 0, i)))
			return (-1);
		if (ret == 1)
			if (!(tmp = ft_strdup(*s + (i + 1))))
				return (-1);
		free(*s);
		*s = tmp;
		return (ret);
	}
	free(*s);
	*s = NULL;
	if (!(*line = ft_strdup("")))
		return (-1);
	return (0);
}

static int		ft_done(char **s, int ret, char **line)
{
	if (ret == -1)
		return (-1);
	if (ret == 0 && *s == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (ft_cutline(s, line));
}

int				get_next_line(int fd, char **line)
{
	static char	*s = NULL;
	int			ret;
	char		*tmp;
	char		buf[BUFFER_SIZE + 1];

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = gnl_strjoin(s, buf)))
			return (-1);
		free(s);
		s = tmp;
		if (ft_strchr(s, '\n'))
			break ;
	}
	return (ft_done(&s, ret, line));
}
