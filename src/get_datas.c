#include "../headers/cub3d.h"
#include "../Libft/libft.h"

static void      skip_char(char **s, int c)
{
    while (**s == c)
        (*s)++;
}

int             add_tex_path(t_struct *datas, char *s, int i, char tex[4][3])
{
    skip_char(&s, ' ');
    while ((**tex)++ == *s)
        skip_char(&s, **tex);
    skip_char(&s, ' ');
    if (*s)
        datas->tex[i].name = ft_strdup(s); // <--- NEED TO FREE !!!!!!!!!
    return (0);
}

int            ft_get_color(t_struct *datas, char *s)
{
    skip_char(&s, ' ');
    (void)datas;
    if (*s == 'F')
    {
        s++;
        // faire un atoi puis un itoa puis une convertion en int quand c'est de l'hexa
    }
    return (0);
}

int            add_sprit_path(t_struct *datas, char *s)
{
    skip_char(&s, ' ');
    if (*s == 'S')
    {
        s++;
        skip_char(&s, ' ');
        datas->sprit.name = ft_strdup(s); // <---- NEED TO FREE !!!!!
    }
    else
        return (6);
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
        return (0);
    }
    else
        return (5);
}