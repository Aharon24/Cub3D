/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:12:43 by ahapetro          #+#    #+#             */
/*   Updated: 2025/12/25 17:17:47 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_draw_c(int color, t_cube **stt, int i, int j)
{
	while (i < (*stt)->g.win_x)
	{
		j = (*stt)->g.win_y / 2 ;
		while (j < (*stt)->g.win_y)
		{
			put_pixel(i, j, color, &(*stt)->g);
			j++;
		}
		i++;
	}
}

void	ft_draw_f(int color, t_cube **stt, int i, int j)
{
	while (i < (*stt)->g.win_x)
	{
		j = 0;
		while (j < (*stt)->g.win_y)
		{
			put_pixel(i, j, color, &(*stt)->g);
			j++;
		}
		i++;
	}
}

void	ft_draw_part(t_cube **stt, int color, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (c == 'c')
		ft_draw_c(color, stt, i, j);
	else
		ft_draw_f(color, stt, i, j);
}

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= game->win_x || y >= game->win_y || x < 0 || y < 0)
		return ;
	index = y * game->s_l + x * game->bpp / 8;
	game->data[index] = color & 0xff;
	game->data[index + 1] = (color >> 8) & 0xff;
	game->data[index + 2] = (color >> 16) & 0xff;
}

int	get_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}
