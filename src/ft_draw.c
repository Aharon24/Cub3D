/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:12:43 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/09 17:28:30 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_draw_c(int color, t_game *g, int i, int j)
{
	while (i < g->win_x)
	{
		j = g->win_y / 2 ;
		while (j < g->win_y)
		{
			put_pixel(i, j, color, g);
			j++;
		}
		i++;
	}
}

void	ft_draw_f(int color, t_game *g, int i, int j)
{
	while (i < g->win_x)
	{
		j = 0;
		while (j < g->win_y)
		{
			put_pixel(i, j, color, g);
			j++;
		}
		i++;
	}
}

void	ft_draw_part(t_game *g, int color, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (c == 'c')
		ft_draw_c(color, g, i, j);
	else
		ft_draw_f(color, g, i, j);
}

int	get_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	ft_draw_floor_cealing(t_game *g)
{
	int	f_pix_x;
	int	c_pix_x;

	g->win_x = WIDTH;
	g->win_y = HEIGHT;
	f_pix_x = g->win_x / 2;
	c_pix_x = g->win_x;
	g->f_color = get_color(g->co->f_1, g->co->f_2, g->co->f_3);
	g->c_color = get_color(g->co->c_1, g->co->c_2, g->co->c_3);
	ft_draw_part(g, g->f_color, 'f');
	ft_draw_part(g, g->c_color, 'c');
}
