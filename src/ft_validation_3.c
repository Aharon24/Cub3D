#include "../include/cub3D.h"

int ft_chesk_side(char **map, int x, int y, int len_x)
{
    int len_y;

    len_y = ft_strlen(map[x]);
    if (x - 1 < len_x && x + 1 < len_x  &&  y - 1 < len_y &&  y + 1 < len_y)
    {
        if (map[x][y - 1] == ' ' || map[x][y + 1]  ==  ' ')
            return (1);
        else if (map[x - 1][y] == ' ' || map[x + 1][y]  ==  ' ')
            return (1);
    }
    return (0);
}

int ft_flood_file_chesk(char **map)
{
    int i;
    int j;
    int len;
    i = 1;

    len = 0;
    while (map[len])
        len++;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (ft_chesk_side(map, i, j, len) && map[i][j] != '1')
            {
                printf("--%c--\n",map[i][j]);
                printf("Error\n");
                printf("wrong map %s \n int x-> %d y -> %d ",map[i],i,j);
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}


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

char *ft_strdup_no_newline(const char *line) 
{
    size_t len;
	char *copy;
	size_t i;

	i = 0;
	len = strlen(line);
    if (len > 0 && line[len - 1] == '\n')
	{
        len--;
	}
	copy = malloc(len + 1);
    if (!copy)
        return NULL;
    while (i < len)
	{
		copy[i] = line[i];
		i++;
	}
    copy[len] = '\0';
    return copy;
}
