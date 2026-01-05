/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:44:56 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/05 17:45:21 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_init_player(t_player *player, t_cube **st)
{
	player->p_x = (*st)->player_x;
	player->p_y = (*st)->player_y;
	player->left = false;
	player->rigth = false;
	player->p_up = false;
	player->p_down = false;
	player->p_rigth = false;
	player->p_left = false;
}
