#include "../include/cub3D.h"

int	main(int ac, char *argv[])
{
	t_cube	*stt;

	stt = NULL;
	if (ac != 2)
	{
		printf("Error\n");
		printf("Problem with argument we need file\n");
		return (1);
	}
	else
	{
		if (ft_validation(argv[1]) != 0)
		{
			return (1);
		}
	}
	stt = ft_start_work(argv[1]);
	if (stt == NULL)
		return (1);
	ft_game(stt);
	ft_free_st(&stt);
	return (0);
}
