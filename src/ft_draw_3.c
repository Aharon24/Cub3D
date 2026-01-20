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
void    ft_draw_wall_slice(t_game *g, float dist, int screen_x, float angle)
{
   // int     wall_height;
    int     y;
    int     color;
    t_tex   *tex;
    int     real_wall_height; // Nuzhna dlya tochnogo rascheta tekstury

    if (dist < 0.1f)
        dist = 0.1f;
    
    // Real'naya vysota mozhet byt' bol'she ekrana (naprimer 3000 pikseley)
    real_wall_height = (int)(B * HEIGHT / dist);
    
    // Opredelyaem granitsy risovaniya na ekrane
    g->start_y = HEIGHT / 2 - real_wall_height / 2;
    g->end = HEIGHT / 2 + real_wall_height / 2;

    // Vybiraem teksturu (peredayem ugol)
    tex = ft_get_wall_tex(g, angle);

    y = g->start_y;
    // Esli stena vyshe ekrana, nachinaem risovat' s 0 piksel'ya ekrana
    if (y < 0) y = 0;
    
    int draw_end = g->end;
    if (draw_end >= HEIGHT) draw_end = HEIGHT - 1;

    while (y < draw_end)
    {
        // Peredayem real_wall_height, chtoby tex_y schitalsya pravil'no
        color = ft_get_wall_pixel(g, tex, y, real_wall_height);
        
        // Esli nuzhna ten' dlya ob"yema (bokovyye steny chut' temneye)
        if (g->hit_vertical)
            color = (color >> 1) & 0x7F7F7F; // Umen'shaem yarkost' v 2 raza
            
        put_pixel(screen_x, y, color, g);
        y++;
    }
}

// void	ft_draw_line(t_player *p, t_game *g, float angle, int screen_x)
// {
// 	float	ray_x;
// 	float	ray_y;
// 	float	step;

// 	ray_x = p->x;
// 	ray_y = p->y;
// 	step = 0.1f;
// 	while (1)
// 	{
// 		p->prev_x = ray_x;
// 		ray_x += cos(angle) * step;
// 		ray_y += sin(angle) * step;
// 		if (ft_wall_chesk(ray_x, ray_y, g))
// 		{
// 			g->ray_x = ray_x;
// 			g->ray_y = ray_y;
// 			g->hit_vertical = ((int)(p->prev_x / B) != (int)(ray_x / B));
// 			break ;
// 		}
// 	}
// 	p->dist = hypot(ray_x - p->x, ray_y - p->y);
// 	p->dist *= cos(angle - p->angle);
// 	if (p->dist < 0.1f)
// 		p->dist = 0.1f;
// 	ft_draw_wall_slice(g, p->dist, screen_x);
// }


void ft_draw_line(t_player *p, t_game *g, float angle, int screen_x)
{
    float ray_dir_x = cos(angle);
    float ray_dir_y = sin(angle);

    // Tekushchaya kletka na karte, gde nakhoditsya igrok
    int map_x = (int)(p->x / B);
    int map_y = (int)(p->y / B);

    // Dlina lucha ot tekushchey pozitsii do sleduyushchey storony kletki
    float side_dist_x;
    float side_dist_y;

    // Rasstoyaniye, kotoroye nuzhno proyti luchu ot odnoy linii setki do sleduyushchey
    float delta_dist_x = fabs(1 / ray_dir_x);
    float delta_dist_y = fabs(1 / ray_dir_y);

    int step_x;
    int step_y;

    // Vychislyayem napravleniye shaga i nachal'noye rasstoyaniye
    if (ray_dir_x < 0) {
        step_x = -1;
        side_dist_x = (p->x / B - map_x) * delta_dist_x;
    } else {
        step_x = 1;
        side_dist_x = (map_x + 1.0 - p->x / B) * delta_dist_x;
    }
    if (ray_dir_y < 0) {
        step_y = -1;
        side_dist_y = (p->y / B - map_y) * delta_dist_y;
    } else {
        step_y = 1;
        side_dist_y = (map_y + 1.0 - p->y / B) * delta_dist_y;
    }

    // Osnovnoy tsikl DDA
    int hit = 0;
    while (hit == 0) {
        // Prygayem v sleduyushchuyu kletku setki
        if (side_dist_x < side_dist_y) {
            side_dist_x += delta_dist_x;
            map_x += step_x;
            g->hit_vertical = 1; // Udar v vertikal'nuyu storonu (West/East)
        } else {
            side_dist_y += delta_dist_y;
            map_y += step_y;
            g->hit_vertical = 0; // Udar v gorizontal'nuyu storonu (North/South)
        }
        // Proveryayem, ne udarilis' li v stenu
        if (g->map[map_y][map_x] == '1')
            hit = 1;
    }

    // Vychislyayem perpendikulyarnuyu distantsiyu (chtoby ne bylo fish-eye)
    float wall_dist;
    if (g->hit_vertical == 1)
        wall_dist = (side_dist_x - delta_dist_x);
    else
        wall_dist = (side_dist_y - delta_dist_y);

    // Sokhranyayem distantsiyu (perevodim v piksely, umnozhaya na razmer bloka B)
    p->dist = wall_dist * B;

    // Raschet tochnoy koordinaty udara na stene (dlya tekstur)
    float wall_hit_point;
    if (g->hit_vertical == 1)
        wall_hit_point = p->y / B + wall_dist * ray_dir_y;
    else
        wall_hit_point = p->x / B + wall_dist * ray_dir_x;
    wall_hit_point -= floor(wall_hit_point);

    // Peredayem wall_hit_point v g dlya ispol'zovaniya v ft_get_wall_pixel
    g->ray_x = wall_hit_point; 

    ft_draw_wall_slice(g, p->dist, screen_x,angle);
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
