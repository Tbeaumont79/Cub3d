#include "../headers/cub3d.h"
#include "../Libft/libft.h"

// faire le check de la map faire en sorte que tout soit good avant de l'ajouter dans la structure !
// gerer le cas ou il y a pas de spawn et bien gerer que la map soit fermer !!
// la map peu ne pas avoir de sprit

int     ft_is_dir(char c)
{
    return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
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
    return (0);
}

void    map_into_struct(t_struct *datas, char *s)
{
    int i;
    int j;

    ft_check_map(datas, s);
    i = 0;
    if (!(datas->game.map = malloc(sizeof(int *) * datas->game.m_h)))
        return ;
    while (i < datas->game.m_h)
    {
        j = 0;
        if (!(datas->game.map[i] = malloc(sizeof(int) * datas->game.m_w)))
            return ;
        while (j < datas->game.m_w)
        {
            // check aussi le premier char de chaque ligne et le dernier
            if (ft_isdigit(*s) || ft_is_dir(*s))
            {
                if ((i == 0 && *s != '1') || (i + 1 == datas->game.m_h && *s != '1'))
                    ft_error("map is not closed !");
                datas->game.map[i][j] = *s - '0';
                j++;
            }
            s++;
        }

        i++;
    }
}