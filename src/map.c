#include "../headers/cub3d.h"
// faire le check de la map faire en sorte que tout soit good avant de l'ajouter dans la structure !
// gerer le cas ou il y a pas de spawn et bien gerer que la map soit fermer !!
// la map peu ne pas avoir de sprit

void    ft_count(char *s, t_struct *datas)
{
    datas->game.wall = s[i] == '1' ? datas->game.wall + 1 : 0;
}

void    ft_check_map(char *s, t_struct *datas)
{
    int i;

    i = -1;
    if (s[i] == '1')
        while (s[++i] == '1')
            ft_count(s[i]);
    
}

void    map_into_struct(t_struct *datas, int map[mapWidth][mapHeight])
{
    int i;
    int j;

    i = 0;
	if (!(datas->game.map = (int **)malloc(sizeof(int*) + (mapWidth * mapHeight) + 1)))
		return ;
    while (i < mapHeight)
    {
        j = 0;
        if (!(datas->game.map[i] = (int *)malloc(sizeof(int) * mapHeight + 1)))
            return ;
        while (j < mapWidth)
        {
            datas->game.map[i][j] = map[i][j];
            j++;
        }
        i++;
    }
}