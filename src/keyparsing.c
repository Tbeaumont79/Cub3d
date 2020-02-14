#include "../headers/cub3d.h"
#include <unistd.h>

// probleme pour quitter le programme proprement surement du au faite que l'event du keyhook n'est pas bon !
int    keypress(int keyval, void *param)
{
    t_struct *datas;

    datas = (t_struct *)param;
    datas->game.key[key_up] = keyval == 126 ? keyval : 0;
    datas->game.key[key_down] = keyval == 125 ? keyval : 0;
    datas->game.key[key_right] = keyval == 124 ? keyval : 0;
    datas->game.key[key_left] = keyval == 123 ? keyval : 0;
    datas->game.key[key_escape] = keyval == 53 ? keyval : 0;
    datas->game.key[key_red] = keyval == 17 ? keyval : 0;
    keyparsing(keyval, datas);
    return (0);
}

int     keyunpress(int keyval, void *param)
{
    t_struct *datas;

    datas = (t_struct *)param;
    datas->game.key[key_up] = keyval == 126 ? 0 : 0;
    datas->game.key[key_down] = keyval == 125 ? 0 : 0;
    datas->game.key[key_right] = keyval == 124 ? 0 : 0;
    datas->game.key[key_left] = keyval == 123 ? 0 : 0;
    datas->game.key[key_escape] = keyval == 53 ? 0 : 0;
    datas->game.key[key_red] = keyval == 17 ? 0 : 0;
    return (0);
}

int    keyparsing(int keyvalue, void *param)
{
    t_struct *datas;
    
    datas = (t_struct *)param;
    static int (*fct[6])(t_struct *datas) = {move_up, move_down,
    move_right, move_left, quit, quit};
    int i;

    i = -1; 
    while (++i < key_len)
        if (keyvalue == datas->game.key[i])
            break ;
    if (i >= 0 && i < key_len)
        return (fct[i](datas));
    return (0);
}