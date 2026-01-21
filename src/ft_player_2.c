/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:30:23 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/16 19:30:42 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_empty_second(t_cube **st, char *map_i, int i)
{
	if (ft_empty(map_i) == 1 && (*st)->c == 1)
		return (ft_exit_count_line());
	if (ft_empty(map_i) == 1 && (*st)->c == 0)
		i++;
	return (0);
}

void	ft_move_3(t_game *g, float cos_angle, float sin_angle, float s)
{
	float	new_x;
	float	new_y;

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
