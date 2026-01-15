/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:14:32 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/15 18:17:09 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

float	ft_distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

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

void	ft_draw_line(t_player *player, t_game *game, float start_x, int i)
{
	float	cos_angle;
	float	sin_angle;
	float	dist;
	float	height;

	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	game->ray_x = player->x;
	game->ray_y = player->y;
	while (!ft_touch(game->ray_x, game->ray_y, game))
	{
		// if (DEBUG)
		put_pixel(game->ray_x / 4, game->ray_y / 4, 0xFF0000, game);
		game->ray_x += cos_angle;
		game->ray_y += sin_angle;
	}
	dist = fixed_dist(game->ray_x, game->ray_y, game);
	height = (B / dist) * (WIDTH / 2);
	game->start_y = (HEIGHT - height) / 2;
	game->end = game->start_y + height;
	game->wall_tex = ft_get_wall_tex(game, game->ray_x, start_x);
	while (game->start_y < game->end)
	{
		game->color = ft_get_wall_pixel(game, game->wall_tex, game->start_y);
		put_pixel(i, game->start_y, game->color, game);
		game->start_y++;
	}
}

bool	ft_touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / B;
	y = py / B;
	if (game->map[y][x]  && game->map[y][x] == '1')
		return (true);
	return (false);
}
