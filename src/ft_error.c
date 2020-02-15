#include "../headers/cub3d.h"
#include "../Libft/libft.h"

void    ft_puterr(char *err, char *s)
{
    write(1, err, (int)ft_strlen(err));
    write(1, s, (int)ft_strlen(s));
}

int     ft_error(char *s)
{
    ft_puterr("error : ", s);
    return (-1);
}