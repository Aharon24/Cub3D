/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_Esc_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:07:13 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/11 19:03:59 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_exit_count_line(void)
{
	printf("Error\n");
	printf("Wrong map game map must not split\n");
	return (-1);
}

int	ft_exit_main(void)
{
	printf("Error\n");
	printf("Problem with argument we need file\n");
	return (1);
}

void	ft_distroy(t_game *g)
{
	if (g->img_s.img)
		mlx_destroy_image(g->mlx, g->img_s.img);
	if (g->img_w.img)
		mlx_destroy_image(g->mlx, g->img_w.img);
	if (g->img_e.img)
		mlx_destroy_image(g->mlx, g->img_e.img);
	if (g->img_n.img)
		mlx_destroy_image(g->mlx, g->img_n.img);
	if (g->win)
	{
		mlx_destroy_window(g->mlx, g->win);
		mlx_destroy_display(g->mlx);
	}
	if (g->mlx)
	{
		free(g->mlx);
		g->mlx = NULL;
	}
}

int	ft_handle_key(int keycode, t_cube **st)
{
	if (keycode == 65307)
	{
		ft_distroy((*st)->g);
		ft_free_st(st);
		exit(0);
	}
	return (0);
}

int	ft_handle_destroy(t_cube	**st)
{
	ft_distroy((*st)->g);
	ft_free_st(st);
	exit(0);
	return (0);
}
