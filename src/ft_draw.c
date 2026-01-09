/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:12:43 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/09 12:45:58 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_draw_c(int color, t_game *g, int i, int j)
{
	while (i < g->win_x)
	{
		j = g->win_y / 2 ;
		while (j < g->win_y)
		{
			put_pixel(i, j, color, g);
			j++;
		}
		i++;
	}
}

void	ft_draw_f(int color, t_game *g, int i, int j)
{
	while (i < g->win_x)
	{
		j = 0;
		while (j < g->win_y)
		{
			put_pixel(i, j, color, g);
			j++;
		}
		i++;
	}
}

void	ft_draw_part(t_game *g, int color, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (c == 'c')
		ft_draw_c(color, g, i, j);
	else
		ft_draw_f(color, g, i, j);
}


void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->s_l + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

int	get_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}
