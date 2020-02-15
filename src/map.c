#include "../headers/cub3d.h"
// faire le check de la map faire en sorte que tout soit good avant de l'ajouter dans la structure !
// gerer le cas ou il y a pas de spawn et bien gerer que la map soit fermer !!
// la map peu ne pas avoir de sprit
void map_into_struct(t_struct *datas, int map[mapWidth][mapHeight])
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