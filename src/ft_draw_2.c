/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:41:51 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/09 12:53:58 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"



void ft_draw_map(t_game *g)
{
	int color = 0X0000FF;
	int i;
	int j;
	
	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == '1')
				ft_draw_square(j * BLOCK, i * BLOCK, BLOCK, color, g);
			j++;
		}
		i++;
	}
}


void	ft_draw_square(int x, int y, int size, int color, t_game *game)
{
	int	i;

	i = 0;
	while (i < size)
	{
		put_pixel(x + i, y, color,game);
		i++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel(x, y + i, color,game);
		i++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel(x + size, y + i, color,game);
		i++;
	}
	i = 0;
	while (i < size)
	{
		put_pixel(x + i, y + size, color,game);
		i++;
	}
}
