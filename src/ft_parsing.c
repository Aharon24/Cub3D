#include "cub3D.h"

t_cube	*ft_parsing_map(char **map, t_cube **st)
{
	ft_init_xpm(*st);
	if (ft_count_line(map, st) == -1)
		return (NULL);
	return (*st);
}

int	ft_count_line(char **map, t_cube **st)
{
	int	i;
	int	count;
	int c;

	c = 0;
	i = 0;
	count = 0;
	while (map[i])
	{
		//ft_chesk_n_s_w_e(st);
		if (ft_empty(map[i]) == 1 && c == 0)
			i++;
		else if(ft_check_valid_map(map[i], *st) == 1)
		{
			//ft_creat_main_map(i,st);
			printf("map\n");
			(*st)->start_creating_map = 1;
			c = 1;
			i++;
		}
		else if (c == 0)
		{
			printf(" path\n");
		    ft_create_arr_path(map[i], st);
			if ((*st)->color_check == 1 || (*st)->path_check == 1)
			{
				///free()
				return (-1);
			}
		    count++;
		    i++;
		}
		else
		{
			printf("Error\n");
			printf("wrong map in map you can use (0,1,N,W,S,E or n,w,s,e and ' ')\n line -> %d",i);
			return (-1);
		}
	}
	return (0);
}

int	ft_check_line(char *str, t_cube **st)
{
	if (ft_strncmp(str, "./path_to_the_north_texture", 27) == 0)
		ft_set_up_path(st, 1);
	else if (ft_strncmp(str, "./path_to_the_south_texture", 27) == 0)
		ft_set_up_path(st, 2);
	else if (ft_strncmp(str, "./path_to_the_west_texture", 26) == 0)
		ft_set_up_path(st, 3);
	else if (ft_strncmp(str, "./path_to_the_east_texture", 26) == 0)
		ft_set_up_path(st, 4);
	else
	{
		printf("%s\n" ,str);
		printf("GAME MAP\n");
		return (-1);
	}
	return (0);
}

int	ft_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_error_file_path(void)
{
	printf("Error\n");
	printf("wrong path in map \n");
	return (-1);
}
