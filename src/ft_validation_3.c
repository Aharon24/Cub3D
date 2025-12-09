#include "../include/cub3D.h"


int ft_chesk_x_y(char c)
{
    if (c == 'S' || c == 'N'
		|| c == 'W' || c == 'E')
        return (0);
	else if (c == 's' || c == 'n'
			|| c == 'w' || c == 'e')
        return (0);
    return (1);
}

void ft_find_player_point(t_cube **st, char **map)
{
    int i;
    int j;
    (*st)->player_x = 0;
    (*st)->player_y = 0;
    i = 0;
    while (map[i])
    {
        j = 0;
        (*st)->player_x = i;
        while (map[i][j])
        {
            if(!ft_chesk_x_y(map[i][j]))
            {
                (*st)->player_y = j;
                return;
            }
            j++;
        }
        i++;
    }

}