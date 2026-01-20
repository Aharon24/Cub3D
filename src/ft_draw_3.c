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

void	ft_draw_wall_slice(t_game *g, float dist, int screen_x, float angle)
{
	int		color;
	t_tex	*tex;
	int		real_wall_height;
	int		draw_end;

	if (dist < 0.1f)
		dist = 0.1f;
	real_wall_height = (int)(B * HEIGHT / dist);
	g->start_y = HEIGHT / 2 - real_wall_height / 2;
	g->end = HEIGHT / 2 + real_wall_height / 2;
	tex = ft_get_wall_tex(g, angle);
	g->ft_d_y = g->start_y;
	if (g->ft_d_y < 0)
		g->ft_d_y = 0;
	draw_end = g->end;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	while (g->ft_d_y < draw_end)
	{
		color = ft_get_wall_pixel(g, tex, g->ft_d_y, real_wall_height);
		if (g->hit_vertical)
			color = (color >> 1) & 0x7F7F7F;
		put_pixel(screen_x, g->ft_d_y, color, g);
		g->ft_d_y++;
	}
}

void	ft_init_line(t_player *p, float angle)
{
	p->delta_dist_x = fabs(1 / p->ray_dir_x);
	p->delta_dist_y = fabs(1 / p->ray_dir_y);
	p->map_x = (int)(p->x / B);
	p->map_y = (int)(p->y / B);
	p->ray_dir_x = cos(angle);
	p->ray_dir_y = sin(angle);
}

void	ft_second_part(t_player *p)
{
	if (p->ray_dir_x < 0)
	{
		p->step_x = -1;
		p->side_dist_x = (p->x / B - p->map_x) * p->delta_dist_x;
	}
	else
	{
		p->step_x = 1;
		p->side_dist_x = (p->map_x + 1.0 - p->x / B) * p->delta_dist_x;
	}
	if (p->ray_dir_y < 0)
	{
		p->step_y = -1;
		p->side_dist_y = (p->y / B - p->map_y) * p->delta_dist_y;
	}
	else
	{
		p->step_y = 1;
		p->side_dist_y = (p->map_y + 1.0 - p->y / B) * p->delta_dist_y;
	}
}

void	ft_three_part(t_player *p, t_game *g)
{
	p->hit = 0;
	while (p->hit == 0)
	{
		if (p->side_dist_x < p->side_dist_y)
		{
			p->side_dist_x += p->delta_dist_x;
			p->map_x += p->step_x;
			g->hit_vertical = 1;
		}
		else
		{
			p->side_dist_y += p->delta_dist_y;
			p->map_y += p->step_y;
			g->hit_vertical = 0;
		}
		if (g->map[p->map_y][p->map_x] == '1')
			p->hit = 1;
	}
}

void	ft_draw_line(t_player *p, t_game *g, float angle, int screen_x)
{
	ft_init_line(p, angle);
	ft_second_part(p);
	ft_three_part(p, g);
	if (g->hit_vertical == 1)
		p->wall_dist = (p->side_dist_x - p->delta_dist_x);
	else
		p->wall_dist = (p->side_dist_y - p->delta_dist_y);
	p->dist = p->wall_dist * B;
	if (g->hit_vertical == 1)
		p->wall_hit_point = p->y / B + p->wall_dist * p->ray_dir_y;
	else
		p->wall_hit_point = p->x / B + p->wall_dist * p->ray_dir_x;
	p->wall_hit_point -= floor(p->wall_hit_point);
	g->ray_x = p->wall_hit_point;
	ft_draw_wall_slice(g, p->dist, screen_x, angle);
}
