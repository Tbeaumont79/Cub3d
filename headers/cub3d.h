#ifndef __CUB3D__H
# define __CUB3D__H

# define screenWidth 1000
# define screenHeight 1000
# define mapWidth 24
# define mapHeight 24
# define key_len 5

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef enum s_value
{
    key_up,
    key_down,
    key_right,
    key_left,
    key_escape,
}              key_value;

typedef struct       s_algo
{
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
    double moveSpeed;
    double rotSpeed;
    double cameraX;
    double rayDirX;
    double rayDirY;
    int mapX;
    int mapY;
    int map[mapWidth][mapHeight];
    double sideDistX;
    double sideDistY;
    double deltaDistX;
    double deltaDistY;
	double perpWallDist;
    int stepX;
    int stepY;
    int hit;
    int side;
    int lineHeight;
    int drawStart;
    int drawEnd;
    double oldDirX;
    double oldPlaneX;
    int x;
}                   t_algo;

typedef struct      s_game
{
    int key[key_len];
    int **map;
}                   t_game;

typedef struct      s_image
{
    void *ptr;
    void *win;
    int *datas;
    void *img;
    int endian;
    int size_line;
    int bpp;
    int color;
    int pixel;
}                   t_image;

typedef struct      s_struct
{
    t_image img;
    t_algo algo;
    t_game game;
}                   t_struct;

void    draw_sky(t_struct *datas);
void    draw_flor(t_struct *datas);
void    draw(t_struct *datas);
int     keypress(int keyval, void *param);
int     keyparsing(int keyvalue, void *param);
void    ft_raycasting(t_struct *datas);
void    map_into_struct(t_struct *datas, int map[mapWidth][mapHeight]);
int     move_up(t_struct *datas);
int     move_down(t_struct *datas);
int     move_right(t_struct *datas);
int     move_left(t_struct *datas);
int     quit(t_struct *datas);
void    init_raycasting_var(t_struct *datas);
void    init_raycasting_var_in_loop(t_struct *datas, int w, int h);
void	render(t_struct *datas);
void    init_img(t_struct *datas);



#endif