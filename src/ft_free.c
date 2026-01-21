/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:40:53 by ahapetro          #+#    #+#             */
/*   Updated: 2025/12/25 14:40:54 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_free_wnes(t_cube **st)
{
	if ((*st)->cub_w)
		free((*st)->cub_w);
	if ((*st)->cub_s)
		free((*st)->cub_s);
	if ((*st)->cub_n)
		free((*st)->cub_n);
	if ((*st)->cub_e)
		free((*st)->cub_e);
}

void	ft_free_two_dimensional_array(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

void	ft_free_arr_map(t_cube **st)
{
	if ((*st)->c_map)
	{
		ft_free_two_dimensional_array((*st)->c_map);
		(*st)->c_map = NULL;
	}
	if ((*st)->normalayz_map)
	{
		ft_free_two_dimensional_array((*st)->normalayz_map);
		(*st)->normalayz_map = NULL;
	}
	if ((*st)->map_for_flood)
	{
		ft_free_two_dimensional_array((*st)->map_for_flood);
		(*st)->map_for_flood = NULL;
	}
	if ((*st)->west)
	{
		free((*st)->west);
		(*st)->west = NULL;
	}
}

void	ft_free_st(t_cube **st)
{
	ft_free_wnes(st);
	ft_free_arr_map(st);
	if ((*st)->south)
	{
		free((*st)->south);
		(*st)->south = NULL;
	}
	if ((*st)->north)
	{
		free((*st)->north);
		(*st)->north = NULL;
	}
	if ((*st)->east)
	{
		free((*st)->east);
		(*st)->east = NULL;
	}
	if (*st)
	{
		free(*st);
		*st = NULL;
	}
}
