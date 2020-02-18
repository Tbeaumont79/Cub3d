#ifndef __CUB3D__H
# define __CUB3D__H

# define screenWidth 1000
# define screenHeight 1000
# define mapWidth 24
# define mapHeight 24
# define key_len 6
# define texWidth 64
# define texHeight 64
# define BUFFER_SIZE 32

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef enum s_value
{
    key_up,
    key_down,
    key_right,
    key_left,
    key_escape,
    key_red,
}            t_value;

typedef struct       s_algo
{
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
    double wallX;
    double moveSpeed;
    double rotSpeed;
    double cameraX;
    double rayDirX;
    double rayDirY;
    double zbuff[screenWidth];
    int mapX;
    int mapY;
    int **map;
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
    int texX[4];
    int texY[4];
    int texNum;
    double texPos;
    double step;
    double s_x;
    double s_y;
    double invet;
    double trans_x;
    int screenx;
    int s_h;
    int s_w;
    int dend_x;
    int dend_y;
    int dstart_x;
    int dstart_y;
    int sprit_tex_y;
    int sprit_tex_x;
    char *s_name;
}                   t_algo;

typedef struct      s_game
{
    int key[key_len];
    int spaw_dir;
    int num_spawn;
    int **map;
    int wall;
    int num_sprit;
    unsigned long flor_color;
    unsigned long rof_color;
    int m_h;
    int m_w;
    int w_h;
    int w_w;
}                   t_game;

typedef struct      s_tex
{
    void *tex_img;
    void *tex;
    char *name;
    int endian;
    int size_line;
    int bpp;
    int *datas;
    int t_h;
    int t_w;
}                   t_tex;

typedef struct      s_sprit
{
    int *sprite_order;
    int *sprite_distance;
    int posx;
    int posy;
}                   t_sprit;

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
    t_algo  algo;
    t_game  game;
    t_sprit *sprit;
    t_tex   tex[4];
}                   t_struct;

void    draw_sky(t_struct *datas);
void    draw_flor(t_struct *datas);
void    draw(t_struct *datas);
int     keypress(int keyval, void *param);
int     keyparsing(void *param);
void    ft_raycasting(t_struct *datas);
int     map_into_struct(t_struct *datas, char *s);
void     move_up(t_struct *datas);
void     move_down(t_struct *datas);
void     move_right(t_struct *datas);
void     move_left(t_struct *datas);
void     quit(t_struct *datas);
void    init_raycasting_var(t_struct *datas);
void    init_raycasting_var_in_loop(t_struct *datas, int w, int h);
void	render(t_struct *datas);
void    init_img(t_struct *datas);
int     keyunpress(int keyval, void *param);
void    choose_tex(t_struct *datas, int *color, int val);
void    init_algo_tex(t_struct *datas);
int    ft_get_texture(t_struct *datas);
int     ft_error(char *s);
void    ft_puterr(char *err, char *s);
char	*gnl_strjoin(char const *s1, char *s2);
int		get_next_line(int fd, char **line);
int     add_reso(t_struct *datas, char *s);
int     ft_read_file(char *filename, t_struct *datas);
int     add_tex_path(t_struct *datas, char *s, int i);
void    skip_char(char **s, int c);
int     add_sprit_path(t_struct *datas, char *s);
int     ft_get_color(t_struct *datas, char *s);
int     ft_check_map(t_struct *datas, char *s);
int     check_all(t_struct *datas);




#endif