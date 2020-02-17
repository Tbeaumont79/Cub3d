#include "../headers/cub3d.h"
#include "../Libft/libft.h"

 int    ft_check_file_name(char *str)
 {
     return (!ft_strstr(str, ".cub") ? ft_error("not a good map name") : 1);
 }

int     ft_parse_text(char *s, t_struct *datas)
{
    static char tex[4][3] = {{"NO"}, {"SO"}, {"WE"}, {"EA"}};
    int         i;

    i = -1;
    while (++i < 4)
        if (ft_strstr(s, tex[i]))
            break ;
    return (i >= 0 && i < 4 ? add_tex_path(datas, s, i) : 4);
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

    s = NULL;
    ret = 0;
     if (!ft_check_file_name(filename))
        return (-1);
    if ((fd = open(filename, O_RDONLY)) == -1)
        ft_error("not a valid file");
    while ((ret = get_next_line(fd, &line)) >= 0)
    {
        ft_parse(line, datas);
        if (*line == '1')
        {
            s = gnl_strjoin(s, line); // pensez a free et evitez les pertes d'address !
            s = gnl_strjoin(s, "\n");
        }
        free(line);
        if (ret == 0)
            break ;
    }
    map_into_struct(datas, s);
    return (0);
 }
