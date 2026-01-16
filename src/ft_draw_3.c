/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:14:32 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/16 19:22:18 by ahapetro         ###   ########.fr       */
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

// void	ft_draw_line(t_player *player, t_game *game, float start_x, int i)
// {
// 	float	cos_angle;
// 	float	sin_angle;
// 	float	dist;
// 	float	height;

// 	cos_angle = cos(start_x);
// 	sin_angle = sin(start_x);
// 	game->ray_x = player->x;
// 	game->ray_y = player->y;
// 	while (!ft_touch(game->ray_x, game->ray_y, game))
// 	{
// 		if (DEBUG)
// 			put_pixel(game->ray_x / 4, game->ray_y / 4, 0xFF0000, game);
// 		game->ray_x += cos_angle;
// 		game->ray_y += sin_angle;
// 	}
// 	dist = fixed_dist(game->ray_x, game->ray_y, game);
// 	height = (B / dist) * (WIDTH / 2);
// 	game->start_y = (HEIGHT - height) / 2;
// 	game->end = game->start_y + height;
// 	game->wall_tex = ft_get_wall_tex(game, game->ray_x,  start_x);
// 	while (game->start_y < game->end)
// 	{
// 		game->color = ft_get_wall_pixel(game, game->wall_tex, game->start_y);
// 		put_pixel(i, game->start_y, 0xFF0000, game);
// 		//ft_draw_map_four(game->wall_tex, game);
// 		game->start_y++;
// 	}
// }

void	ft_draw_line(t_player *p, t_game *g, float angle, int screen_x)
{
	float	ray_x;
	float	ray_y;

	ray_x = p->x;
	ray_y = p->y;
	p->step = 1.0f;
	while (1)
	{
		p->prev_x = ray_x;
		ray_x += cos(angle) * p->step;
		ray_y += sin(angle) * p->step;
		if (ft_wall_chesk(ray_x, ray_y, g))
		{
			g->ray_x = ray_x;
			g->ray_y = ray_y;
			if ((int)(p->prev_x / B) != (int)(ray_x / B))
				g->hit_vertical = 1;
			else
				g->hit_vertical = 0;
			break ;
		}
	}
	p->dist = hypot(ray_x - p->x, ray_y - p->y);
	p->dist *= cos(angle - p->angle);
	ft_draw_wall_slice(g, p->dist, screen_x);
}

void	ft_draw_wall_slice(t_game *g, float dist, int screen_x)
{
	int		wall_height;
	int		y;
	int		color;
	t_tex	*tex;

	wall_height = (int)(B * HEIGHT / dist);
	g->start_y = HEIGHT / 2 - wall_height / 2;
	g->end = HEIGHT / 2 + wall_height / 2;
	if (g->start_y < 0)
		g->start_y = 0;
	if (g->end >= HEIGHT)
		g->end = HEIGHT - 1;
	tex = ft_get_wall_tex(g);
	y = g->start_y;
	while (y < g->end)
	{
		color = ft_get_wall_pixel(g, tex, y);
		put_pixel(screen_x, y, color, g);
		y++;
	}
}

bool	ft_touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / B;
	y = py / B;
	if (game->map[y][x] && game->map[y][x] == '1')
		return (true);
	return (false);
}
