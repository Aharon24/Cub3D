/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:41:51 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/09 17:36:19 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

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

void	ft_draw_map(t_game *g)
{
	int	color;
	int	i;
	int	j;

	color = 0XFFFFFF;
	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == '1')
				ft_draw_square(j * B / 4, i * B / 4, B / 4, color, g);
			j++;
		}
		i++;
	}
}

void	ft_draw_square(int x, int y, int size, int color, t_game *game)
{
	game->i_25l = 0;
	while (game->i_25l < size)
	{
		put_pixel(x + game->i_25l, y, color, game);
		game->i_25l++;
	}
	game->i_25l = 0;
	while (game->i_25l < size)
	{
		put_pixel(x, y + game->i_25l, color, game);
		game->i_25l++;
	}
	game->i_25l = 0;
	while (game->i_25l < size)
	{
		put_pixel(x + size, y + game->i_25l, color, game);
		game->i_25l++;
	}
	game->i_25l = 0;
	while (game->i_25l < size)
	{
		put_pixel(x + game->i_25l, y + size, color, game);
		game->i_25l++;
	}
}
