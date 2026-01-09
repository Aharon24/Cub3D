/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:14:32 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/09 14:37:33 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

float ft_distance(float x, float y)
{
    return sqrt(x * x + y * y);
}

float fixed_dist(float x1, float y1, float x2, float y2, t_game *game)
{
	float delta_x;
	float delta_y;
	float angle;
	float fix_dist;
	

	delta_y = y2 - y1;
	delta_x = x2 - x1;
	angle = atan2(delta_y,delta_x) - game->player.angle;
	fix_dist = ft_distance(delta_x, delta_y) *  cos(angle);
	return (fix_dist);
}

void ft_draw_line(t_player *player, t_game *game, float start_x, int i)
{
	float cos_angle;
	float sin_angle;
	float ray_x;
	float ray_y;
	float dist;
	float height;
	int start_y;
	int end;

	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	ray_x = player->x;
	ray_y = player->y;
	while (!ft_touch(ray_x,ray_y, game))
	{
		// if (DEBUG)
		// 	put_pixel(ray_x, ray_x, 0xFF0000, game);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
	if (!DEBUG)
	{
		dist = fixed_dist(player->x, player->y,ray_x,ray_y,game);
		height = (BLOCK / dist) * (WIDTH / 2);
		start_y = (HEIGHT - height) / 2;
		end = start_y + height;
		while (start_y < end)
		{
			put_pixel(i, start_y,255,game);
			start_y++;
		}
	}
}


bool ft_touch(float px, float py, t_game *game)
{
	int x;
	int y;

	x = px / BLOCK;
	y = py / BLOCK;
	if (game->map[y][x] == '1')
		return (true);
	return (false);
}