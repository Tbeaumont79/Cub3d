#include "../headers/cub3d.h"
#include <unistd.h>

// probleme pour quitter le programme proprement surement du au faite que l'event du keyhook n'est pas bon !
int    keypress(int keyval, void *param)
{
    t_struct *datas;

    datas = (t_struct *)param;
    datas->game.key[key_up] = keyval == 13 ? keyval : datas->game.key[key_up];
    datas->game.key[key_down] = keyval == 1 ? keyval : datas->game.key[key_down];
    datas->game.key[key_right] = keyval == 2 ? keyval : datas->game.key[key_right];
    datas->game.key[key_left] = keyval == 0 ? 1 : datas->game.key[key_left];
    datas->game.key[rot_left] = keyval == 123 ? keyval : datas->game.key[rot_left];
    datas->game.key[rot_right] = keyval == 124 ? keyval : datas->game.key[rot_right];
    datas->game.key[key_escape] = keyval == 53 ? keyval : 0;
    return (0);
}

int     keyunpress(int keyval, void *param)
{
    t_struct *datas;

    datas = (t_struct *)param;
    datas->game.key[key_up] = keyval == 13 ? 0 : datas->game.key[key_up];
    datas->game.key[key_down] = keyval == 1 ? 0 : datas->game.key[key_down];
    datas->game.key[key_right] = keyval == 2 ? 0 : datas->game.key[key_right];
    datas->game.key[key_left] = 1 == 0 ? 0 : 0;
    datas->game.key[rot_left] = keyval == 123 ? 0 : datas->game.key[rot_left];
    datas->game.key[rot_right] = keyval == 124 ? 0 : datas->game.key[rot_right];
    datas->game.key[key_escape] = keyval == 53 ? 0 : 0;
    return (0);
}

int    keyparsing(void *param)
{
    t_struct *datas;
    
    datas = (t_struct *)param;
    static void (*fct[7])(t_struct *datas) = {move_up, move_down,
    move_right, move_left, quit, rotate_left, rotate_right};
    
    if (datas->game.key[key_up])
        fct[0](datas);
    if (datas->game.key[key_down])
        fct[1](datas);
    if (datas->game.key[key_right])
        fct[2](datas);
    if (datas->game.key[key_left])
        fct[3](datas);
    if (datas->game.key[key_escape])
        fct[4](datas);
    if (datas->game.key[rot_left])
        fct[5](datas);
    if (datas->game.key[rot_right])
        fct[6](datas);
    ft_raycasting(datas);    
    return (0);
}