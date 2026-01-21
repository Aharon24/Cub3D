/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:40:56 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/16 19:33:11 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_wall_chesk(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = (int)(px / B);
	y = (int)(py / B);
	if (y < 0 || x < 0)
		return (1);
	if (!game->map || !game->map[y])
		return (1);
	if (x >= (int)ft_strlen(game->map[y]))
		return (1);
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
	g->player.delta_dist_x = 0;
	g->player.delta_dist_y = 0;
	g->player.map_x = 0;
	g->player.map_y = 0; 
	g->player.ray_dir_x = 0; 
	g->player.ray_dir_y = 0; 

}

void	ft_draw_walls_one_time(t_game *game)
{
	float		fraction;
	float		start_angle;
	int			screen_x;
	t_player	*player;

	player = &game->player;
	start_angle = player->angle - PI / 6;
	fraction = PI / 3 / WIDTH;
	screen_x = 0;
	while (screen_x < WIDTH)
	{
		ft_draw_line(player, game, start_angle, screen_x);
		start_angle += fraction;
		screen_x++;
	}
	ft_draw_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
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
	ft_get_picture(stt);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, ft_key_release, &game);
	mlx_hook(game.win, 17, 0, ft_handle_destroy, stt);
	mlx_loop_hook(game.mlx, ft_draw_loop, &game);
	mlx_loop(game.mlx);
}
