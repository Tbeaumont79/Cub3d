#include "../headers/cub3d.h"

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