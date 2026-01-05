/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:41:51 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/05 17:44:21 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_draw_loop(t_cube **st)
{
	ft_move_player(st);
	ft_draw_square((*st)->player.p_x, (*st)->player.p_y, 5, 0x00FFFF, st);
	mlx_put_image_to_window((*st)->g.mlx, (*st)->g.win, (*st)->g.img, 0, 0);
	return (0);
}

void	ft_draw_square(int x, int y, int size, int color, t_cube **st)
{
	int	i;

	i = 0;
	while (i < size)
	{
		put_pixel(x + i, y, color, &(*st)->g);
		i++;
	}
	while (i < size)
	{
		put_pixel(x, y + i, color, &(*st)->g);
		i++;
	}
	while (i < size)
	{
		put_pixel(x + size, y + i, color, &(*st)->g);
		i++;
	}
	while (i < size)
	{
		put_pixel(x + i, y + size, color, &(*st)->g);
		i++;
	}
}
