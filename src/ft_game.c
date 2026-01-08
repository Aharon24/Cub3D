/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:40:56 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/08 18:15:08 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_player_key_click(t_player *player, t_cube **st)
{
	ft_init_player(player, st);
	mlx_hook((*st)->g.win, 2, 1L << 0, key_press, &st);
	mlx_hook((*st)->g.win, 3, 1L << 1, ft_key_update, &st);
	mlx_loop_hook((*st)->g.win, ft_draw_loop, st);
}


void	ft_draw_floor_cealing(t_cube **stt)
{
	(*stt)->g.f_color = get_color((*stt)->co.f_1,
			(*stt)->co.f_2, (*stt)->co.f_3);
	(*stt)->g.c_color = get_color((*stt)->co.c_1,
			(*stt)->co.c_2, (*stt)->co.c_3);
	ft_draw_part(stt, (*stt)->g.f_color, 'f');
	ft_draw_part(stt, (*stt)->g.c_color, 'c');
}

void	ft_create_window(t_cube **s)
{
	ft_init_player(&(*s)->player, s);
	(*s)->g.mlx = mlx_init();
	(*s)->g.win = mlx_new_window((*s)->g.mlx, (*s)->g.win_x,(*s)->g.win_y, "cub3D");
	(*s)->g.img = mlx_new_image((*s)->g.mlx, (*s)->g.win_x, (*s)->g.win_y);
	(*s)->g.data = mlx_get_data_addr((*s)->g.img, &(*s)->g.bpp,&(*s)->g.s_l, &(*s)->g.e_d);
	mlx_put_image_to_window((*s)->g.mlx, (*s)->g.win, (*s)->g.img, 0, 0);
}

void	ft_game(t_cube **stt)
{
	(*stt)->g.win_x = 2600;
	(*stt)->g.win_y = 1800;
	(*stt)->f_pix_x = (*stt)->g.win_x / 2;
	(*stt)->c_pix_x = (*stt)->g.win_x;
	ft_create_window(stt);
	mlx_hook((*stt)->g.win, 2, 1L << 0, key_press, stt);
	mlx_hook((*stt)->g.win, 3, 1L << 1, ft_key_update, stt);
	mlx_loop_hook((*stt)->g.mlx, ft_draw_loop, stt);
	
	ft_draw_floor_cealing(stt);
	ft_player_key_click(&(*stt)->player, stt);
	ft_draw_loop(stt);
	// ft_craete_game_map(stt);
	//ft_draw_square(1600 /2, 1600 / 2, 10, 0x00FFFF, stt);
	mlx_loop((*stt)->g.mlx);
}

// void draw_square(int x, int y, int size, int color, t_game **game)
// {

// }