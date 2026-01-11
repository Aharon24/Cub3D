/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_Esc_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:07:13 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/11 19:03:59 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_handle_key(int keycode, t_cube **st)
{
	if (keycode == 65307)
	{
		ft_free_st(st);
		printf("ESC\n");
		exit(0);
	}
	return (0);
}

int	ft_handle_destroy(t_cube	**st)
{
	ft_free_st(st);
	printf("X\n");
	exit(0);
	return (0);
}
