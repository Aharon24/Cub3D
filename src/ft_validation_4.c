/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:41:35 by ahapetro          #+#    #+#             */
/*   Updated: 2025/12/25 14:41:36 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_w_s_e_n_dup(t_cube **st, int type, int fd, char *path)
{
	if (type == 1 && fd != -1)
	{
		if ((*st)->north)
			free((*st)->north);
		(*st)->north = ft_strdup(path);
	}
	if (type == 2 && fd != -1)
	{
		if ((*st)->south)
			free((*st)->south);
		(*st)->south = ft_strdup(path);
	}
	if (type == 3 && fd != -1)
	{
		if ((*st)->west)
			free((*st)->west);
		(*st)->west = ft_strdup(path);
	}
	if (type == 4 && fd != -1)
	{
		if ((*st)->east)
			free((*st)->east);
		(*st)->east = ft_strdup(path);
	}
}

void	ft_open_path(t_cube **st, char *path, int type)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1 && type == 1)
		(*st)->north = ft_strdup("x");
	if (fd == -1 && type == 2)
		(*st)->south = ft_strdup("x");
	if (fd == -1 && type == 3)
		(*st)->west = ft_strdup("x");
	if (fd == -1 && type == 4)
		(*st)->east = ft_strdup("x");
	ft_w_s_e_n_dup(st, type, fd, path);
	close(fd);
}

void	ft_crate_path_value(t_cube **st, char **arr)
{
	if ((ft_strncmp(arr[0], "NO", 2) == 0) && (ft_strlen(arr[0]) == 2))
		ft_open_path(st, arr[1], 1);
	else if ((ft_strncmp(arr[0], "SO", 2) == 0) && (ft_strlen(arr[0]) == 2))
		ft_open_path(st, arr[1], 2);
	else if ((ft_strncmp(arr[0], "WE", 2) == 0) && (ft_strlen(arr[0]) == 2))
		ft_open_path(st, arr[1], 3);
	else if ((ft_strncmp(arr[0], "EA", 2) == 0) && (ft_strlen(arr[0]) == 2))
		ft_open_path(st, arr[1], 4);
}

int	ft_empty_chesk(char **map)
{
	int	i;
	int	len;
	int	e;

	e = 0;
	len = 0;
	i = 0;
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
