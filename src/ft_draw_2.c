/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:41:51 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/08 18:23:45 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_draw_loop(t_cube **st)
{
	t_player *player = &(*st)->player;
    move_player(player);
    clear_image((*st)->g);
    if(DEBUG)
    {
        ft_draw_square(player->x, player->y, 10, 0x00FF00, st);
        ft_draw_map(st);
    }
    float fraction = PI / 3 / WIDTH;
    float start_x = player->angle - PI / 6;
    int i = 0;
    while(i < WIDTH)
    {
        draw_line(player, game, start_x, i);
        start_x += fraction;
        i++;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
    return 0;
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
