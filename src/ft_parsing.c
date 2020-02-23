/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:37:37 by thbeaumo          #+#    #+#             */
/*   Updated: 2020/02/21 16:58:07 by thbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include "../Libft/libft.h"

int		ft_check_file_name(char *str)
{
	return (!ft_strstr(str, ".cub") ? ft_error("not a good map name") : 1);
}

int		ft_parse_text(char *s, t_struct *datas)
{
	static char tex[5][3] = {{"NO"}, {"SO"}, {"WE"}, {"EA"}, {"FO"}};
	int         i;

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
	ft_get_color(datas , str);
	ft_fill_s(datas, str);
	return (0); 
}

int		ft_read_file(char *filename, t_struct *datas)
{
	int    fd;
	char   *line;
	char   *tmp;
	char   *tmp2;

	datas->algo.s = NULL;
	if (!ft_check_file_name(filename))
		return (-1);
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_error("not a valid file");
	while ((datas->algo.ret = get_next_line(fd, &line)) >= 0)
	{
		if (datas->game.m_line)
			datas->game.m_space++;
		ft_parse(line, datas);
		free(line);
		if (datas->algo.ret == 0)
			break ;
	}
	if ((map_into_struct(datas, datas->algo.s)) == -1)
		return (-1);
	free(datas->algo.s);
	close(fd);
	return (0);
}
