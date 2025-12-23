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
		printf("wrong map only(0,1,N,W,S,E or n,w,s,e and' ')\nline -> %d", i);
	}
	return (-1);
}

int	ft_error_file_path(void)
{
	printf("Error\n");
	printf("wrong path in map \n");
	return (-1);
}

t_cube	*ft_st_null(int fd)
{
	printf("Error\n");
	printf("wrong map \n");
	close(fd);
	return (NULL);
}

void	ft_error_validation_two(int player)
{
	printf("Error\n");
	printf("pleeyer must start game in one point not %d\n", player);
}

t_cube	*ft_error_start_work(void)
{
	printf("malloc problem");
	return (NULL);
}
