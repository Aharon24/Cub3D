/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:12:43 by ahapetro          #+#    #+#             */
/*   Updated: 2025/12/25 15:22:10 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"


void    ft_draw_part(t_cube **stt, int color)
{
    int i;
    int j;

    i = 0;    
    while(i < (*stt)->f_pix_x)
    {
        j = 0;
        while (j < (*stt)->game.win_y)
        {
            put_pixel(i,j,color,&(*stt)->game);
            j++;
        }
        i++;
    }
    
}

void put_pixel(int x, int y, int color, t_game *game)
{
	int index;

	if (x >= game->win_x || y >= game->win_y || x < 0 || y < 0)
		return ;
	index = y * game->size_len + x * game->bpp / 8;
	game->data[index] = color & 0xff;	
	game->data[index + 1] = (color >> 8) & 0xff;
	game->data[index + 2] = (color >> 16) & 0xff;
}

int get_color(int r, int g, int b)
{
    return (r << 16) | (g << 8) | b;
}
