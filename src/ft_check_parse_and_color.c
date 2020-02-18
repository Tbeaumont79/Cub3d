#include "../headers/cub3d.h"

int check_all(t_struct *datas)
{
    if (datas->game.num_spawn == 0)
        return (ft_error("there is no spawn on the map !\n"));
    if (datas->game.num_spawn > 1)
        return (ft_error("there is too much spawn !\n"));
    if (datas->game.num_sprit > 0 && datas->algo.s_name == NULL)
        return (ft_error("invalide sprit path !\n"));
    if (datas->game.flor_color == 0)
        return (ft_error("the flor has no color set !\n"));
    if (datas->game.rof_color == 0)
        return (ft_error("the roof has no color set !\n"));
    if (datas->game.w_w == 0)
        return (ft_error("the windows width is not set ! \n"));
    if (datas->game.w_h == 0)
        return (ft_error("the windows heigth is not set ! \n"));
    return (0);
}