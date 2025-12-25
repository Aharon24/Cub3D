/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:40:56 by ahapetro          #+#    #+#             */
/*   Updated: 2025/12/25 17:14:51 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

// void	ft_craete_game_map(t_cube **stt)
// {
// }

void	ft_draw_floor_cealing(t_cube **stt)
{
	(*stt)->g.f_color = get_color((*stt)->co.f_1,
			(*stt)->co.f_2, (*stt)->co.f_3);
	(*stt)->g.c_color = get_color((*stt)->co.c_1,
			(*stt)->co.c_2, (*stt)->co.c_3);
	ft_draw_part(stt, (*stt)->g.f_color, 'f');
	ft_draw_part(stt, (*stt)->g.c_color, 'c');
	mlx_put_image_to_window((*stt)->g.mlx, (*stt)->g.win, (*stt)->g.img, 0, 0);
}

void	ft_create_window(t_cube **s)
{
	(*s)->g.mlx = mlx_init();
	(*s)->g.win = mlx_new_window((*s)->g.mlx, (*s)->g.win_x,
			(*s)->g.win_y, "cub3D");
	(*s)->g.img = mlx_new_image((*s)->g.mlx, (*s)->g.win_x, (*s)->g.win_y);
	(*s)->g.data = mlx_get_data_addr((*s)->g.img, &(*s)->g.bpp,
			&(*s)->g.s_l, &(*s)->g.e_d);
}

void	ft_game(t_cube **stt)
{
	(*stt)->g.win_x = 1600;
	(*stt)->g.win_y = 1600;
	(*stt)->f_pix_x = (*stt)->g.win_x / 2;
	(*stt)->c_pix_x = (*stt)->g.win_x;
	ft_create_window(stt);
	ft_draw_floor_cealing(stt);
	// ft_craete_game_map(stt);
	mlx_loop((*stt)->g.mlx);
}

// void draw_square(int x, int y, int size, int color, t_game **game)
// {

// }