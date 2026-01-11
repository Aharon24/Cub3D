/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:40:56 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/11 19:08:19 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_wall_chesk(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / B;
	y = py / B;
	if (game->map[y][x] == '1')
		return (1);
	return (0);
}

void	ft_clear_image(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			put_pixel(j, i, 0, game);
			j++;
		}
		i++;
	}
}

void	ft_init_game(t_game *g)
{
	ft_init_player(&g->player);
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, "cub3D");
	g->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	g->data = mlx_get_data_addr(g->img, &g->bpp, &g->s_l, &g->e_d);
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
}

int	ft_draw_loop(t_game *game)
{
	float		fraction;
	float		start_x;
	int			i;
	t_player	*player;

	player = &game->player;
	ft_move_player(game);
	ft_clear_image(game);
	ft_draw_floor_cealing(game);
	fraction = PI / 3 / WIDTH;
	start_x = game->player.angle - PI / 6;
	i = 0;
	while (i < WIDTH)
	{
		ft_draw_line(player, game, start_x, i);
		start_x += fraction;
		i++;
	}
	ft_draw_map(game);
	ft_draw_square(player->x / 4, player->y / 4, 3, 0x00FF00, game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

void	ft_game(t_cube **stt)
{
	t_game	game;

	game.map = (*stt)->normalayz_map;
	game.co = &(*stt)->co;
	(*stt)->g = &game;
	(*stt)->g->player.y = (*stt)->player_x * B + B / 2 ;
	(*stt)->g->player.x = (*stt)->player_y * B + B / 2 ;
	ft_init_game(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, ft_key_release, &game);
	mlx_hook(game.win, 17, 0, ft_handle_destroy, stt);
	mlx_loop_hook(game.mlx, ft_draw_loop, &game);
	mlx_loop(game.mlx);
}
