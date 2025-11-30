#include "../include/cub3D.h"

int	ft_error(int subject, int i)
{
	if (subject == 1)
	{
		printf("Error\n");
		printf("Wrong count path  or color\n");
	}
	else if (subject == 2)
	{
		printf("Error\n");
		printf("wrong map only(0,1,N,W,S,E or n,w,s,e and' ')\n line ->%d", i);
	}
	return (-1);
}
