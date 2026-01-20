/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:12:56 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/16 19:17:56 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

float	fixed_dist(float x2, float y2, t_game *game)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_dist;

	delta_y = y2 - game->player.y;
	delta_x = x2 - game->player.x;
	angle = atan2(delta_y, delta_x) - game->player.angle;
	fix_dist = ft_distance(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}

float	ft_distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

int	ft_draw_loop(t_game *game)
{
	t_player	*player;

	player = &game->player;
	ft_move_player(game);
	ft_clear_image(game);
	ft_draw_floor_cealing(game);
	ft_draw_walls_one_time(game);
	game->ft_size = 3;
	ft_draw_square(player->x / 4, player->y / 4, 0x00FF00, game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}
