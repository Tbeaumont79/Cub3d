#include "../headers/cub3d.h"
#include "../Libft/libft.h"

 int    ft_check_file_name(char *str)
 {
     return (!ft_strstr(str, ".cub") ? ft_error("not a good map name") : 1);
 }

int     ft_parse_text(char *s, t_struct *datas)
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

int     ft_parse(char *s, t_struct *datas)
{
    add_reso(datas, s);
    ft_parse_text(s, datas);
    add_sprit_path(datas, s);
    ft_get_color(datas , s);
    return (0); 
}

 int    ft_read_file(char *filename, t_struct *datas)
 {
     int    fd;
     char   *line;
     char   *s;
     int    ret;
     char   *tmp;
     char   *tmp2;

    s = NULL;
    ret = 0;
     if (!ft_check_file_name(filename))
        return (-1);
    if ((fd = open(filename, O_RDONLY)) == -1)
        ft_error("not a valid file");
    while ((ret = get_next_line(fd, &line)) >= 0)
    {
        if (datas->game.m_line)
            datas->game.m_space++;
        ft_parse(line, datas);
        if (*line == '1')
        {
            if (datas->game.m_parsed < 5)
                return (ft_error("map not at the end of file !"));
            tmp = gnl_strjoin(s, line); // pensez a free et evitez les pertes d'address !
            free(s);
            s = tmp;
            tmp2 = gnl_strjoin(s, "\n");
            free(s);
            s = tmp2;
            datas->game.m_line++;
        }
        free(line);
        if (ret == 0)
            break ;
    }
    if ((map_into_struct(datas, s)) == -1)
        return (-1);
    free(s);
    return (0);
 }
