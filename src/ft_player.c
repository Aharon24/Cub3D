/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:44:56 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/09 16:55:43 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_move_2(t_player *player, float cos_angle, float sin_angle, float s)
{
	if (player->key_up)
	{
		player->x += cos_angle * s;
		player->y += sin_angle * s;
	}
	if (player->key_down)
	{
		player->x -= cos_angle * s;
		player->y -= sin_angle * s;
	}
	if (player->key_left)
	{
		player->x += sin_angle * s;
		player->y -= cos_angle * s;
	}
	if (player->key_right)
	{
		player->x -= sin_angle * s;
		player->y += cos_angle * s;
	}
}

void	ft_init_player(t_player *player)
{
	player->x = WIDTH / 2;
	player->y = HEIGHT / 2;
	player->angle = PI / 2;
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

void	ft_move_player(t_player *player)
{
	int		speed;
	float	angle_speed;
	float	cos_angle;
	float	sin_angle;

	sin_angle = sin(player->angle);
	cos_angle = cos(player->angle);
	angle_speed = 0.1;
	speed = 5;
	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
	{
		player->angle = 2 * PI;
	}
	ft_move_2(player, cos_angle, sin_angle, speed);
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
	else if (keycode == LEFT)
		game->player.left_rotate = false;
	else if (keycode == RIGHT)
		game->player.right_rotate = false;
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.key_up = true;
	else if (keycode == S)
		game->player.key_down = true;
	else if (keycode == A)
		game->player.key_left = true;
	else if (keycode == D)
		game->player.key_right = true;
	else if (keycode == 65361)
		game->player.left_rotate = true;
	else if (keycode == 65363)
		game->player.right_rotate = true;
	return (0);
}
