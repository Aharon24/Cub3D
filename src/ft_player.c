#include "../include/cub3D.h"


void ft_init_player(t_player *player, t_cube **st)
{
	player->p_x = (*st)->player_x;
	player->p_y = (*st)->player_y;
	printf( "x ->  %d  y -> %d \n", (*st)->player_x,(*st)->player_y);
	player->left = false;
	player->rigth = false;
	player->p_up = false;
	player->p_down = false;
	player->p_rigth = false;
	player->p_left = false;
}