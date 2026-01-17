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

t_tex	*ft_get_wall_tex(t_game *g)
{
	if (g->hit_vertical)
	{
		if (g->ray_x > g->player.x)
			return (&g->img_e);
		else
			return (&g->img_w);
	}
	else
	{
		if (g->ray_y > g->player.y)
			return (&g->img_s);
		else
			return (&g->img_n);
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
	printf("%s 1\n",(*st)->cub_e);
	printf("%s 2\n",(*st)->cub_n);
	printf("%s 3\n",(*st)->cub_s);
	printf("%s 4\n",(*st)->cub_w);
	ft_load_texture(g, &g->img_w, (*st)->cub_w);
	ft_load_texture(g, &g->img_s, (*st)->cub_s);
	ft_load_texture(g, &g->img_e, (*st)->cub_e);
	ft_load_texture(g, &g->img_n, (*st)->cub_n);
}

int	ft_get_wall_pixel(t_game *game, t_tex *w, int y)
{
	float	hit_x;
	int		block_x;
	int		block_y;
	float	wall_height;

	block_x = (int)(game->ray_x / B);
	block_y = (int)(game->ray_y / B);
	wall_height = game->end - game->start_y;
	if (game->hit_vertical)
		hit_x = (game->ray_y - block_y * B) / (float)B;
	else
		hit_x = (game->ray_x - block_x * B) / (float)B;
	if (hit_x < 0.0f)
		hit_x = 0.0f;
	if (hit_x > 1.0f)
		hit_x = 1.0f;
	w->tex_x = (int)(hit_x * w->width);
	if (w->tex_x >= w->width)
		w->tex_x = w->width - 1;
	w->tex_y = (int)(((y - game->start_y) * w->height) / wall_height);
	if (w->tex_y < 0)
		w->tex_y = 0;
	if (w->tex_y >= w->height)
		w->tex_y = w->height - 1;
	return (ft_get_tex_pixel(w, w->tex_x, w->tex_y));
}

int	ft_get_tex_pixel(t_tex *tex, int x, int y)
{
	char	*pixel_addr;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	pixel_addr = tex->data + (y * tex->s_l + x * (tex->bpp / 8));
	return (*(unsigned int *)pixel_addr);
}
