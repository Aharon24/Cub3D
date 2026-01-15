/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_picture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:39:41 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/15 16:01:00 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"


void ft_get_picture(t_cube **st)
{
	int h;
	int w;

	(*st)->g->img_w = mlx_xpm_file_to_image((*st)->g->mlx,(*st)->west,&h,&w);
	(*st)->g->img_s =mlx_xpm_file_to_image((*st)->g->mlx,(*st)->south,&h,&w);
	(*st)->g->img_e = mlx_xpm_file_to_image((*st)->g->mlx,(*st)->east,&h,&w);
	(*st)->g->img_n = mlx_xpm_file_to_image((*st)->g->mlx,(*st)->north,&h,&w);
}