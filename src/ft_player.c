/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:44:56 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/11 19:05:40 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_move_2(t_game *g, float cos_angle, float sin_angle, float s)
{
	float	new_x;
	float	new_y;

	if (g->player.key_up)
	{
		new_x = g->player.x + cos_angle * s;
		new_y = g->player.y + sin_angle * s;
		if (!ft_wall_chesk(new_x, g->player.y, g))
			g->player.x = new_x;
		if (!ft_wall_chesk(g->player.x, new_y, g))
			g->player.y = new_y;
	}
	if (g->player.key_down)
	{
		new_x = g->player.x - cos_angle * s;
		new_y = g->player.y - sin_angle * s;
		if (!ft_wall_chesk(new_x, g->player.y, g))
			g->player.x = new_x;
		if (!ft_wall_chesk(g->player.x, new_y, g))
			g->player.y = new_y;
	}
	if (g->player.key_left)
	{
		new_x = g->player.x + sin_angle * s;
		new_y = g->player.y - cos_angle * s;
		if (!ft_wall_chesk(new_x, g->player.y, g))
			g->player.x = new_x;
		if (!ft_wall_chesk(g->player.x, new_y, g))
			g->player.y = new_y;
	}
	if (g->player.key_right)
	{
		new_x = g->player.x - sin_angle * s;
		new_y = g->player.y + cos_angle * s;
		if (!ft_wall_chesk(new_x, g->player.y, g))
			g->player.x = new_x;
		if (!ft_wall_chesk(g->player.x, new_y, g))
			g->player.y = new_y;
	}
}

void	ft_init_player(t_player *player)
{
	player->angle = PI / 2;
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

void	ft_move_player(t_game *g)
{
	int		speed;
	float	angle_speed;
	float	cos_angle;
	float	sin_angle;

	sin_angle = sin(g->player.angle);
	cos_angle = cos(g->player.angle);
	angle_speed = 0.1;
	speed = 5;
	if (g->player.left_rotate)
		g->player.angle -= angle_speed;
	if (g->player.right_rotate)
		g->player.angle += angle_speed;
	if (g->player.angle > 2 * PI)
		g->player.angle = 0;
	if (g->player.angle < 0)
	{
		g->player.angle = 2 * PI;
	}
	ft_move_2(g, cos_angle, sin_angle, speed);
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
	else if (keycode == 65307)
	{
		printf("esc\n");
		exit(0);
	}
	return (0);
}
