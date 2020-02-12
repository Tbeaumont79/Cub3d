#include "../headers/cub3d.h"

void    keypress(int keyval, t_struct *datas)
{
    datas->game.key[key_up] = keyval == 126 ? keyval : 0;
    datas->game.key[key_down] = keyval == 125 ? keyval : 0;
    datas->game.key[key_left] = keyval == 123 ? keyval : 0;
    datas->game.key[key_right] = keyval == 124 ? keyval : 0;
    datas->game.key[key_escape] = keyval == 53 ? keyval : 0;
}

int    keyparsing(int keyvalue, t_struct *datas)
{
    static int all_key[key_len] = {{datas->game.key[key_up]},
     {datas->game.key[key_down]}, {datas->game.key[key_left]}, 
     {datas->game.key[key_right]}, {datas->game.key[key_escape]}};
    static int (*fct[5])(t_struct *datas) = {move_up, move_down,
    move_left, move_right, quit};
    int i;

    i = -1; 
    while (++i < key_len)
        if (keyvalue == all_key[i])
            break ;
    if (i >= 0 && i < key_len)
        fct[i](datas);
}
