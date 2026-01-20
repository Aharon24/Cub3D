/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:41:51 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/16 19:16:22 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	put_pixel(int x, int y, int color, t_game *game)
{
	int				index;
	unsigned int	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->s_l + x * (game->bpp / 8);
	if (game->bpp == 32)
	{
		dst = (unsigned int *)(game->data + index);
		*dst = (unsigned int)color;
	}
	else if (game->bpp == 24)
	{
		game->data[index] = color & 0xFF;
		game->data[index + 1] = (color >> 8) & 0xFF;
		game->data[index + 2] = (color >> 16) & 0xFF;
	}
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

int	get_pixel_color(void *img, int x, int y)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		*pixel_color;

	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	pixel_color = (int *)(data + y * size_line + x * (bpp / 8));
	return (*pixel_color);
}

// void ft_draw_square(int x, int y, int size, int color, t_game *game)
// {
//     int i, j;
//     i = 0;
//     while (i < size)
//     {
//         j = 0;
//         while (j < size)
//         {
//             put_pixel(x + j, y + i, color, game);
//             j++;
//         }
//         i++;
//     }
// }

void	ft_draw_square(int x, int y, int size, int color, t_game *game)
{
	game->i_25l = 0;
	while (game->i_25l < size)
	{
		put_pixel(x + game->i_25l, y, color, game);
		put_pixel(x, y + game->i_25l, color, game);
		put_pixel(x + size, y + game->i_25l, color, game);
		put_pixel(x + game->i_25l, y + size, color, game);
		game->i_25l++;
	}
}
