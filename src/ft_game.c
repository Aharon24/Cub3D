#include "../include/cub3D.h"

void	ft_create_window(t_cube **stt)
{
	(*stt)->game.mlx = mlx_init();
	(*stt)->game.win = mlx_new_window((*stt)->game.mlx,3840,2160,"Game");
	(*stt)->game.img = mlx_new_image((*stt)->game.mlx,3840,2160);
}

void	ft_craete_game_map(t_cube  **stt)
{


}

void ft_game(t_cube **stt)
{
	ft_create_window(stt);
	ft_craete_game_map(stt);
	mlx_loop((*stt)->game.mlx);
}