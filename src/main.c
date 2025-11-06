#include "cub3D.h"

int main (int ac, char *argv[])
{
	if (ac != 2)
	{
		printf("Error\n");
		printf("Problem with argument\n");
		return (1);
	}
	else
		ft_validation(argv[1]);
	
	return (0);
}
