#include "../headers/cub3d.h"
#include "../Libft/libft.h"

void      skip_char(char **s, int c)
{
    while (**s == c)
        (*s)++;
}

int             add_tex_path(t_struct *datas, char *s, int i)
{
    int j;

    j = 0;
    skip_char(&s, ' ');
    if (*s)
    {
        datas->tex[i].name = ft_strdup(s); // <--- NEED TO FREE !!!!!!!!!
        datas->game.m_parsed++;
    }
    return (0);
}

unsigned long ft_dec_to_hexa(int r, int g, int b)
{
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int            ft_get_color(t_struct *datas, char *s)
{
    int r;
    int g;
    int b;
    unsigned long hexa_num;

    r = 0;
    g = 0;  
    b = 0;
    skip_char(&s, ' ');
    if (*s == 'F')
    {
        s++;
        r = ft_atoi((const char **)&s);
        skip_char(&s, ',');
        g = ft_atoi((const char **)&s);
        skip_char(&s, ',');
        b = ft_atoi((const char **)&s);
        datas->game.flor_color = ft_dec_to_hexa(r, g, b);
        datas->game.m_parsed++;
    }
    else if (*s == 'C')
    {
        s++;
        r = ft_atoi((const char **)&s);
        skip_char(&s, ',');
        g = ft_atoi((const char **)&s);
        skip_char(&s, ',');
        b = ft_atoi((const char **)&s);
        datas->game.rof_color = ft_dec_to_hexa(r, g, b);
        datas->game.m_parsed++;
    }
    return (0);
}

int            add_sprit_path(t_struct *datas, char *s)
{
    skip_char(&s, ' ');
    if (*s == 'S' && *(s + 1) != 'O')
    {
        s++;
        skip_char(&s, ' ');
        datas->algo.s_name = ft_strdup(s); // <---- NEED TO FREE !!!!!
        datas->game.m_parsed++;
    }
    return (0);
}

int             add_reso(t_struct *datas, char *s)
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