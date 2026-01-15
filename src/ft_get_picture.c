/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_picture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:01:02 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/15 19:06:28 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"


t_tex *ft_get_wall_tex(t_game *g, float ray_x, float ray_y, float angle)
{
	printf("%f",ray_y);
    // Если мы попали точно на вертикальную линию (x делится на B)
    if ((int)ray_x % B == 0)
    {
        if (cos(angle) > 0) // смотрим вправо
            return &g->img_e;
        else                 // смотрим влево
            return &g->img_w;
    }
    else // горизонтальная линия
    {
        if (sin(angle) > 0) // смотрим вниз
            return &g->img_s;
        else                 // смотрим вверх
            return &g->img_n;
    }
}

void	ft_load_texture(t_game *g, t_tex *tex, char *path)
{
	int w;
	int h;

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
	t_game *g = (*st)->g;

	ft_load_texture(g, &g->img_w, (*st)->west);
	ft_load_texture(g, &g->img_s, (*st)->south);
	ft_load_texture(g, &g->img_e, (*st)->east);
	ft_load_texture(g, &g->img_n, (*st)->north);
}

int	ft_get_wall_pixel(t_game *game, t_tex *wall_tex, int y)
{
	int tex_x;
	int tex_y;
	float hit_x;
	float wall_height;

	// вычисляем hit_x
	if ((int)game->ray_x % B == 0)
		hit_x = fmod(game->ray_y, B) / B; // вертикальная стена
	else
		hit_x = fmod(game->ray_x, B) / B; // горизонтальная

	tex_x = (int)(hit_x * wall_tex->width);

	// вычисляем tex_y
	wall_height = game->end - game->start_y;
	tex_y = (int)((y - game->start_y) / wall_height * wall_tex->height);

	return ft_get_tex_pixel(wall_tex, tex_x, tex_y);
}


int	ft_get_tex_pixel(t_tex *tex, int x, int y)
{
	char	*pixel_addr;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);  

	pixel_addr = tex->data + (y * tex->s_l + x * (tex->bpp / 8));

	return (*(unsigned int *)pixel_addr);
}
