#include "../headers/cub3d.h"
#include "mlx.h"

void init_structure(t_struct *datas)
{
    datas->img.ptr = mlx_init();
    datas->img.win = 
    mlx_new_window(datas->img.ptr, screenWidth, screenHeight, "cub3d");
    datas->img.img = 
    mlx_new_image(datas->img.ptr, screenWidth, screenHeight);
    datas->img.datas = (int *)mlx_get_data_addr(datas->img.img, &(datas->img.bpp)
    , &(datas->img.size_line), &(datas->img.endian));
}

void	render(t_struct *datas)
{
    mlx_clear_window(datas->img.ptr, datas->img.win);
	datas->img.img = mlx_new_image(datas->img.ptr, screenWidth, screenHeight);
	datas->img.datas = (int *)mlx_get_data_addr(datas->img.img, &(datas->img.bpp)
    , &(datas->img.size_line), &(datas->img.endian));
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    t_struct *datas;


    if (!(datas = (t_struct *)malloc(sizeof(t_struct))))
        return (0);
		    int worldMap[mapWidth][mapHeight]=
    {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    init_structure(datas);
	map_into_struct(datas, worldMap);
    init_raycasting_var(datas);
	mlx_hook(datas->img.win, 2, 0, keypress, datas);
	mlx_key_hook(datas->img.win, keyparsing, datas);
	render(datas);
    ft_raycasting(datas);
    mlx_loop(datas->img.ptr);
	free(datas->game.map);
	free(datas);
    return (0);
}