/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_picture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:01:02 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/16 19:29:42 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_tex *ft_get_wall_tex(t_game *g, float angle)
{
    if (g->hit_vertical) // Udar v boka (Vostok ili Zapad)
    {
        if (cos(angle) > 0)
            return (&g->img_e); // East
        else
            return (&g->img_w); // West
    }
    else // Udar v verkh/niz (Sever ili Yug)
    {
        if (sin(angle) > 0)
            return (&g->img_s); // South
        else
            return (&g->img_n); // North
    }
}

void	ft_load_texture(t_game *g, t_tex *tex, char *path)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	tex->img = mlx_xpm_file_to_image(g->mlx, path, &w, &h);
	if (!tex->img)
	{
		perror("Error loading texture");
		exit(EXIT_FAILURE);
	}
	tex->width = w;
	tex->height = h;
	tex->data = mlx_get_data_addr(tex->img, &tex->bpp, &tex->s_l, &tex->endian);
}

void	ft_get_picture(t_cube **st)
{
	t_game	*g;

	g = (*st)->g;
	ft_load_texture(g, &g->img_w, (*st)->cub_w);
	ft_load_texture(g, &g->img_s, (*st)->cub_s);
	ft_load_texture(g, &g->img_e, (*st)->cub_e);
	ft_load_texture(g, &g->img_n, (*st)->cub_n);
}
// int ft_get_wall_pixel(t_game *game, t_tex *tex, int y)
// {
//     int tex_x;
//     int tex_y;
//     float wall_height;

//     tex_x = (int)(game->ray_x * (float)tex->width);
//     if ((game->hit_vertical == 1 && cos(game->player.angle) < 0) || 
//         (game->hit_vertical == 0 && sin(game->player.angle) > 0))
//         tex_x = tex->width - tex_x - 1;
//     wall_height = (int)(B * HEIGHT / (game->player.dist));
//     int relative_y = y - game->start_y;
//     tex_y = (int)(relative_y * (float)tex->height / wall_height);
//     if (tex_y < 0) tex_y = 0;
//     if (tex_y >= tex->height) tex_y = tex->height - 1;
//     if (tex_x < 0) tex_x = 0;
//     if (tex_x >= tex->width) tex_x = tex->width - 1;

//     return (ft_get_tex_pixel(tex, tex_x, tex_y));
// }
int ft_get_wall_pixel(t_game *game, t_tex *tex, int y, int wall_h)
{
    int tex_x;
    int tex_y;

    // 1. Koordinata X uzhe rasschitana v ft_draw_line i lezhit v ray_x
    tex_x = (int)(game->ray_x * (float)tex->width);

    // 2. Korrektsiya zerkal'nosti tekstury
    if ((game->hit_vertical == 1 && cos(game->player.angle) < 0) || 
        (game->hit_vertical == 0 && sin(game->player.angle) > 0))
        tex_x = tex->width - tex_x - 1;

    // 3. Tochnyy raschet Y: ispol'zuyem peredannuyu vysotu wall_h.
    // Eto vazhno, potomu chto wall_h mozhet byt' bol'she HEIGHT, 
    // i my dolzhny schitat' otnositel'no real'nogo razmera steny.
    int relative_y = y - game->start_y;
    tex_y = (int)(relative_y * (float)tex->height / wall_h);

    // 4. Strogaya proverka granits, chtoby ne segfaultnut' na krayu tekstury
    if (tex_y < 0) tex_y = 0;
    if (tex_y >= tex->height) tex_y = tex->height - 1;
    if (tex_x < 0) tex_x = 0;
    if (tex_x >= tex->width) tex_x = tex->width - 1;

    return (ft_get_tex_pixel(tex, tex_x, tex_y));
}

int	ft_get_tex_pixel(t_tex *tex, int x, int y)
{
	char	*pixel_addr;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	pixel_addr = tex->data + (y * tex->s_l + x * (tex->bpp / 8));
	return (*(unsigned int *)pixel_addr);
}
