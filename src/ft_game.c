/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:40:56 by ahapetro          #+#    #+#             */
/*   Updated: 2025/12/25 15:31:07 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"


void	ft_draw_floor_cealing(t_cube **stt)
{
	(*stt)->game.f_color = get_color((*stt)->co.f_1,(*stt)->co.f_2,(*stt)->co.f_3);
	(*stt)->game.c_color = get_color((*stt)->co.c_1,(*stt)->co.c_2,(*stt)->co.c_3);
	printf("f %d c %d\n",(*stt)->game.f_color,(*stt)->game.c_color);
	ft_draw_part(stt,(*stt)->game.f_color);
	ft_draw_part(stt,(*stt)->game.c_color);
	mlx_put_image_to_window((*stt)->game.mlx, (*stt)->game.win, (*stt)->game.img, 0, 0);
	
}


void ft_create_window(t_cube **stt)
{
	(*stt)->game.mlx = mlx_init();
	(*stt)->game.win = mlx_new_window((*stt)->game.mlx,(*stt)->game.win_x,(*stt)->game.win_y,"cub3D");
	(*stt)->game.img = mlx_new_image((*stt)->game.mlx,(*stt)->game.win_x,(*stt)->game.win_y);
	(*stt)->game.data = mlx_get_data_addr((*stt)->game.img, &(*stt)->game.bpp, &(*stt)->game.size_len, &(*stt)->game.endian);

}


void ft_game(t_cube **stt)
{
	(*stt)->game.win_x = 1600;
	(*stt)->game.win_y = 1600;
	(*stt)->f_pix_x = (*stt)->game.win_x / 2;
	(*stt)->c_pix_x = (*stt)->game.win_x;
	printf("F  len  %d\n  len %d \n",(*stt)->f_pix_x, (*stt)->c_pix_x);
	ft_create_window(stt);
	ft_draw_floor_cealing(stt);
	//ft_craete_game_map(stt);
	mlx_loop((*stt)->game.mlx);
}



// void draw_square(int x, int y, int size, int color, t_game **game)
// {

// }