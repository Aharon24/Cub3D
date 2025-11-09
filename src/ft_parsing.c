#include "cub3D.h"

t_cube   *ft_parsing_map(char **map, t_cube *st)
{
    ft_count_line(map);
}

int  ft_count_line(char **map)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(map[i])
    {
        if (ft_empty(map[i]) == 1)
            i++;
        else
        {
            ft_check_line(map[i]);
            count++;
            i++;
        }
        ft_chesk_n_s_w_e();

    }
}


int ft_check_line(char *str)
{

}

int ft_empty(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if ((str[i] >= 9 && str <= 13) && str[i] == 32)
            i++;
        else
            return (0);
    }
    return (1);
}

