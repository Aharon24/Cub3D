/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_up_path_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:41:11 by ahapetro          #+#    #+#             */
/*   Updated: 2025/12/25 14:41:12 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_split_check(char *line, t_cube **st)
{
	char	**arr;

	arr = ft_split(line, ' ');
	ft_crate_path_value(st, arr);
	if ((ft_strlen(arr[0]) == 1) && arr[0][0] == 'C')
		ft_check_floor_ceiling(st, arr[1], arr[0][0]);
	else if ((ft_strlen(arr[0]) == 1) && arr[0][0] == 'F')
		ft_check_floor_ceiling(st, arr[1], arr[0][0]);
	else if ((ft_strncmp(arr[0], "NO", 2) == 0) && (ft_strlen(arr[0]) == 2))
		ft_check_line(arr[1], st, 1);
	else if ((ft_strncmp(arr[0], "SO", 2) == 0) && (ft_strlen(arr[0]) == 2))
		ft_check_line(arr[1], st, 2);
	else if ((ft_strncmp(arr[0], "WE", 2) == 0) && (ft_strlen(arr[0]) == 2))
		ft_check_line(arr[1], st, 3);
	else if ((ft_strncmp(arr[0], "EA", 2) == 0) && (ft_strlen(arr[0]) == 2))
		ft_check_line(arr[1], st, 4);
	else
	{
		(*st)->path_check = 1;
		ft_error_file_path();
		ft_free_two_dimensional_array(arr);
		printf("%s\n", line);
		return ;
	}
	ft_free_two_dimensional_array(arr);
}

int	ft_check_valid_map(char *str, t_cube *st)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0' || str[i] == '1')
			i++;
		else if (str[i] == 'S' || str[i] == 'N'
			|| str[i] == 'W' || str[i] == 'E'
			|| str[i] == ' ' || str[i] == '\n')
			i++;
		else if (str[i] == 's' || str[i] == 'n'
			|| str[i] == 'w' || str[i] == 'e'
			|| str[i] == ' ' || str[i] == '\n')
			i++;
		else
		{
			st->main_map_check = 1;
			return (0);
		}
	}
	return (1);
}

int	ft_check_f_c(char **line, t_cube **st)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j])
		{
			if (line[i][j] >= '0' && line[i][j] <= '9')
				j++;
			else
			{
				printf("Error\n");
				printf("It must be number -> %c\n", line[i][j]);
				(*st)->color_check = 1;
				return (-1);
			}
		}
		i++;
	}
	return (0);
}

void	ft_check_floor_ceiling(t_cube **st, char *str, char letter)
{
	char	**line;
	int		i;

	i = 0;
	if (ft_count_comma(str) == 1)
		return ;
	line = ft_split(str, ',');
	if (ft_check_f_c(line, st) == -1)
		return ;
	while (line[i])
		i++;
	if (i != 3)
	{
		printf("Error\n");
		printf("you must write 3 number or use ',' ! ->  %s", str);
		(*st)->color_check = 1;
		return ;
	}
	ft_letter(letter, line, st);
	ft_free_two_dimensional_array(line);
}

int	ft_count_comma(char *str)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			c++;
		i++;
	}
	if (c != 2)
		return (1);
	return (0);
}
