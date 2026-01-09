/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:14:32 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/09 13:45:20 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void ft_draw_line(t_player *player, t_game *game, float start_x, int i)
{
	printf("i%d",i);
	float cos_angle;
	float sin_angle;
	float ray_x;
	float ray_y;
	float dist;
	float height;
	int start

	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	ray_x = player->x;
	ray_y = player->y;

	while (!ft_touch(ray_x,ray_y, game))
	{
		put_pixel(ray_x, ray_x, 0xFF0000, game);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
	dist = ft_distance(ray_x - player->x, ray_y - player->y)
	height = (BLOCK / dist) * (WIDTH / 2);
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