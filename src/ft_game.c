/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:40:56 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/09 15:50:28 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"



void ft_clear_image(t_game *game)
{
	int i;
	int j;
		
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			put_pixel(j,i, 0 ,game);
			j++;
		}
		i++;
	}
}

void ft_init_game(t_game *g)
{
	ft_init_player(&g->player);
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx,WIDTH, HEIGHT,  "cub3D");
	g->img = mlx_new_image(g->mlx,WIDTH, HEIGHT);
	g->data = mlx_get_data_addr(g->img, &g->bpp,&g->s_l, &g->e_d);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
}


int ft_draw_loop(t_game *game)
{
	float fraction;
	float start_x;
	int i;
	t_player *player;

	player = &game->player;
	ft_move_player(player);
	ft_clear_image(game);
	ft_draw_floor_cealing(game);
	// if (DEBUG)
	// {
	// 	ft_draw_map(game);
	// 	ft_draw_square(player->x / 4, player->y / 4, 3, 0x00FF00, game);
	// }
	fraction = PI / 3 / WIDTH;
	start_x = game->player.angle - PI / 6;
	i = 0;
	while (i < WIDTH)
	{
		ft_draw_line(player,game,start_x,i);
		start_x += fraction;
		i++;
	}
	ft_draw_map(game);
	ft_draw_square(player->x / 4, player->y / 4, 3, 0x00FF00, game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}


void	ft_draw_floor_cealing(t_game *g)
{
	g->win_x = WIDTH;
	g->win_y = HEIGHT;
	f_pix_x = g->win_x / 2;
	c_pix_x = g->win_x;
	g->f_color = get_color((*st)-0>co.f_1,(*st)->co.f_2, (*st)->co.f_3);
	g->c_color = get_color((*st)->co.c_1,(*st)->co.c_2, (*st)->co.c_3);
	ft_draw_part((*st)->g, (*st)->g->f_color, 'f');
	ft_draw_part((*st)->g, (*st)->g->c_color, 'c');
}


void	ft_game(t_cube **stt)
{
	t_game game;

	game.map = (*stt)->normalayz_map;
	game.co = &(*stt)->co; 
	(*stt)->g = &game;
 	ft_init_game(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, ft_key_release, &game);
	mlx_loop_hook(game.mlx, ft_draw_loop, &game);
	mlx_loop(game.mlx);
}

