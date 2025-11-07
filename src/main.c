#include "cub3D.h"

int main (int ac, char *argv[])
{
	if (ac != 2)
	{
		printf("Error\n");
		printf("Problem with argument we need file\n");
		return (1);
	}
	else
	{
		if (ft_validation(argv[1]) != 0)
		return (1);
	}
	ft_start_work(argv[1]);
	return (0);
}
