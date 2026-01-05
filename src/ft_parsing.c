/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:41:07 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/05 17:44:36 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_one_for_parsing(t_cube **st)
{
	(*st)->start_creating_map = 1;
	(*st)->c = 1;
}

t_cube	*ft_parsing_map(char **map, t_cube **st)
{
	int	i;

	i = 0;
	if (ft_empty_chesk(map) == 1)
		return (NULL);
	if (ft_count_line(map, st, i) == -1)
		return (NULL);
	if (ft_chekc_norm_map_m((*st)->normalayz_map, st) == 1)
		return (NULL);
	return (*st);
}

int	ft_count_line(char **map, t_cube **st, int i)
{
	while (map[i])
	{
		if (ft_empty(map[i]) == 1 && (*st)->c == 0)
			i++;
		else if (ft_check_valid_map(map[i], *st) == 1)
		{
			if (ft_check_path_count(st) != 0)
				return (ft_error(2, i));
			ft_one_for_parsing(st);
			ft_map_create_for_moveing(map[i], i, st, map);
			if ((*st)->map_valid == 1)
				return (-1);
			i++;
		}
		else if ((*st)->c == 0)
		{
			ft_create_arr_path(map[i], st);
			if ((*st)->color_check == 1 || (*st)->path_check == 1)
				return (-1);
			i++;
		}
		else
			return (ft_error(2, i));
	}
	return (0);
}

int	ft_check_line(char *str, t_cube **st)
{
	if (ft_strncmp(str, (*st)->north, ft_strlen((*st)->north)) == 0
		&& (ft_strlen((*st)->north) == ft_strlen(str)))
	{
		ft_set_up_path(st, 1);
	}
	else if (ft_strncmp(str, (*st)->south, ft_strlen((*st)->south)) == 0
		&& (ft_strlen((*st)->south) == ft_strlen(str)))
	{
		ft_set_up_path(st, 2);
	}
	else if (ft_strncmp(str, (*st)->west, ft_strlen((*st)->west)) == 0
		&& (ft_strlen((*st)->west) == ft_strlen(str)))
	{
		ft_set_up_path(st, 3);
	}
	else if (ft_strncmp(str, (*st)->east, ft_strlen((*st)->east)) == 0
		&& (ft_strlen((*st)->east) == ft_strlen(str)))
		ft_set_up_path(st, 4);
	else
	{
		ft_error_file_path();
		printf ("%s", str);
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
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 || str[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}
