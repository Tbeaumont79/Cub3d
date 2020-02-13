#include "../headers/cub3d.h"
#include <unistd.h>
int    keypress(int keyval, void *param)
{
    t_struct *datas;

    datas = (t_struct *)param;
    datas->game.key[key_up] = keyval == 126 ? keyval : 0;
    datas->game.key[key_down] = keyval == 125 ? keyval : 0;
    datas->game.key[key_right] = keyval == 124 ? keyval : 0;
    datas->game.key[key_left] = keyval == 123 ? keyval : 0;
    datas->game.key[key_escape] = keyval == 53 ? keyval : 0;
    return (0);
}

int    keyparsing(int keyvalue, void *param)
{
    t_struct *datas;
    
    datas = (t_struct *)param;
    static int (*fct[5])(t_struct *datas) = {move_up, move_down,
    move_right, move_left, quit};
    int i;

    i = -1; 
    while (++i < key_len)
        if (keyvalue == datas->game.key[i])
            break ;
    if (i >= 0 && i < key_len)
        return (fct[i](datas));
    return (0);
}