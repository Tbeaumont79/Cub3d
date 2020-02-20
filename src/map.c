#include "../headers/cub3d.h"
#include "../Libft/libft.h"

// faire le check de la map faire en sorte que tout soit good avant de l'ajouter dans la structure !
// gerer le cas ou il y a pas de spawn et bien gerer que la map soit fermer !!
// la map peu ne pas avoir de sprit

int     ft_is_dir(char c)
{
    return (c == 'N' || c == 'S' || c == 'E' || c == 'O');
}

int     ft_check_map(t_struct *datas, char *s)
{
    int j;
    int i;

    j = 0;
    i = 0;
    while (s[i])
    {
        while (s[j] != '\n')
        {
            if (ft_isdigit(s[j]) || ft_is_dir(s[j]))
                datas->game.m_w++;
            j++;
        }
        if (s[i] == '\n')
            datas->game.m_h++;
        i++;
    }
    if ((datas->game.m_h == 0 && datas->game.m_w == 0) ||
    (datas->game.m_space + 1 != datas->game.m_line))
        return (-1);
    return (0);
}

int    map_into_struct(t_struct *datas, char *s)
{
    int i;
    int j;

    if ((ft_check_map(datas, s)) == -1)
        return (ft_error("map is invalid"));
    i = 0;
    if (!(datas->game.map = malloc(sizeof(int *) * datas->game.m_h)))
        return (ft_error("malloc !\n"));
    while (i < datas->game.m_h)
    {
        j = 0;
        if (!(datas->game.map[i] = malloc(sizeof(int) * datas->game.m_w)))
            return (ft_error("malloc !\n"));
        while (j < datas->game.m_w)
        {
            if (ft_isdigit(*s) || ft_is_dir(*s))
            {
                if ((i == 0 && *s != '1') || (i + 1 == datas->game.m_h && *s != '1') ||
                (*s != '1' && j + 1 == datas->game.m_w))
                    return (ft_error("map is not close ! \n"));
                if (ft_is_dir(*s))
                {
                    datas->algo.posX = i + 0.5;
                    datas->algo.posY = j + 0.5;
                    datas->game.spaw_dir = *s;
                    *s = '0';
                    datas->game.num_spawn += 1;
                }
                if (*s == '2')
                    datas->game.num_sprit += 1;
                if (*s == '3')
                    datas->game.sprit_light += 1;
                datas->game.map[i][j] = *s - '0';
                j++;
            }
            s++;
        }
        i++;
    }
    return (0);
}