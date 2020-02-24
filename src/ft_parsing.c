/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:37:37 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/24 17:58:34 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../Libft/libft.h"

int		ft_check_file_name(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (ft_strcmp(&str[i], ".cub") != 0)
				return (ft_error("not a good map name \n"));
		}
		i++;
	}
	return (!ft_strstr(str, ".cub") ? ft_error("not a good map name") : 1);
}

int		ft_parse_text(char *s, t_struct *datas)
{
	static char tex[5][3] = {{"NO"}, {"SO"}, {"WE"}, {"EA"}, {"FO"}};
	int			i;

	i = -1;
	while (++i < 5)
		if (ft_strstr(s, tex[i]))
			break ;
	if (*s == tex[i][0])
		s += ft_strlen(tex[i]);
	return (i >= 0 && i < 5 ? add_tex_path(datas, s, i) : 4);
}

int		ft_parse(char *str, t_struct *datas)
{
	add_reso(datas, str);
	ft_parse_text(str, datas);
	add_sprit_path(datas, str);
	ft_get_color(datas, str);
	if (ft_fill_s(datas, str) == -1)
		return (-1);
	return (0);
}

int		ft_read_file(char *filename, t_struct *datas)
{
	int		fd;
	char	*line;

	datas->algo.s = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (ft_error("invalid file \n"));
	if ((ft_check_file_name(filename)) == -1)
		return (-1);
	while ((datas->algo.ret = get_next_line(fd, &line)) >= 0)
	{
		if (datas->game.m_line)
			datas->game.m_space++;
		if (ft_parse(line, datas) == -1)
			return (-1);
		free(line);
		if (datas->algo.ret == 0)
			break ;
	}
	if (datas->game.m_space == 0)
		return (ft_error("parsing datas not found \n"));
	if ((map_into_struct(datas, datas->algo.s)) == -1)
		return (-1);
	free(datas->algo.s);
	close(fd);
	return (0);
}
