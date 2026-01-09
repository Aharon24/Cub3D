/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:40:56 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/09 11:50:27 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"


void ft_init_game(t_game *g)
{
	ft_init_player(&g->player);
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx,WIDTH, HEIGHT,  "cub3D");
	g->img = mlx_new_image(g->mlx,WIDTH, HEIGHT);
	g->data = mlx_get_data_addr(g->img, &g->bpp,&g->s_l, &g->e_d);
	//mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
}


int ft_draw_loop(t_game *game)
{
	t_player *player = &game->player;
	ft_move_player(player);
	ft_draw_square(player->x, player->y, 5, 0x00FF00, game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}


// void	ft_draw_floor_cealing(t_cube **stt)
// {
// 	(*stt)->g.win_x = 2600;
// 	(*stt)->g.win_y = 1800;
// 	(*stt)->f_pix_x = (*stt)->g.win_x / 2;
// 	(*stt)->c_pix_x = (*stt)->g.win_x;
// 	(*stt)->g.f_color = get_color((*stt)->co.f_1,
// 			(*stt)->co.f_2, (*stt)->co.f_3);
// 	(*stt)->g.c_color = get_color((*stt)->co.c_1,
// 			(*stt)->co.c_2, (*stt)->co.c_3);
// 	ft_draw_part(stt, (*stt)->g.f_color, 'f');
// 	ft_draw_part(stt, (*stt)->g.c_color, 'c');
// }


void	ft_game(t_cube **stt)
{
	t_game game;
	(*stt)->g =&game;
 	ft_init_game(&game);
	
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, ft_key_release, &game);

	mlx_loop_hook(game.mlx, ft_draw_loop, &game);
	mlx_loop(game.mlx);
}

