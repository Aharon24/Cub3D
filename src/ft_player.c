/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:44:56 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/09 11:49:46 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_init_player(t_player *player)
{
	player->x = WIDTH / 2;
	player->y = HEIGHT / 2;

	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
	//player->left = false;
	//player->rigth = false;
	
}


void	ft_move_player(t_player *player)
{
	int	size_walk;

	size_walk = 5;
	if (player->key_up)
		player->y -= size_walk;
	if (player->key_down)
		player->y += size_walk;
	if (player->key_left)
		player->x -= size_walk;
	if (player->key_right)
		player->x += size_walk;
}

int	ft_key_release(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.key_up = false;
	else if (keycode == S)
		game->player.key_down = false;
	else if (keycode == A)
		game->player.key_left = false;
	else if (keycode == D)
		game->player.key_right = false;
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	/*
		W 119
		A 97
		S 115
		D 100
	*/
	if (keycode == W)
		game->player.key_up = true;
	else if (keycode == A)
		game->player.key_left = true;
	else if (keycode == S)
		game->player.key_down = true;
	else if (keycode == D)
		game->player.key_right = true;
	else if (keycode == 65361) // <
		game->player.key_left = true;
	else if (keycode == 65363) // >
		game->player.key_right = true;
	return (0);
}
