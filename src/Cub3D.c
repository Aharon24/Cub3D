/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:12:56 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/16 19:17:56 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_draw_loop(t_game *game)
{
	t_player	*player;

	player = &game->player;
	ft_move_player(game);
	ft_clear_image(game);
	ft_draw_floor_cealing(game);
	ft_draw_walls_one_time(game);
	ft_draw_square(player->x / 4, player->y / 4, 3, 0x00FF00, game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}
