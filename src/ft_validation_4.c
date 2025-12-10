#include "../include/cub3D.h"

int ft_empty_chesk(char **map)
{
	int i;
	int len;
	int e;

	e = 0;
	len = 0;
	i =  0;
	while (map[len])
		len++;
	while (map[i])
	{
		if (ft_empty(map[i]) == 1)
			e++;
		i++;

	}
	if (e == len)
	{
		printf("Error\n");
		printf("wrong map empty and new line \n");
		return (1);
	}
	return (0);
}