#include "../include/cub3D.h"

void	ft_move_player(t_cube **st)
{
	if ((*st)->player.p_up)
		(*st)->player.p_y 
	if ((*st)->player.p_left)

	if ((*st)->player.p_down)
		
	if ((*st)->player.p_rigth)
}
int ft_drow_loop(t_cube **st)
{

}

int ft_key_update(int keycode, t_cube **st)
{
	if (keycode == 119)
		(*st)->player.p_up = false;
	else if (keycode == 97)
		(*st)->player.p_left = false;
	else if (keycode == 115)
		(*st)->player.p_down = false;
	else if (keycode == 100)
		(*st)->player.p_rigth = false;
	return (0);
}

int key_press(int keycode, t_cube **st)
{
	/*
		W 119
		A 97
		S 115
		D 100
	*/
	if (keycode == 119)
	{
		(*st)->player.p_up = true;
		ft_move_player(st);
	}
	else if (keycode == 97)
	{
		(*st)->player.p_left = true;
		ft_move_player(st);
	}
	else if (keycode == 115)
	{
		(*st)->player.p_down = true;
		ft_move_player(st);
	}
	else if (keycode == 100)
	{
		(*st)->player.p_rigth = true;
		ft_move_player(st);
	}
	else if(keycode == 65361) // <
	{
		(*st)->player.left = true;
		ft_move_player(st);
	}
	else if (keycode == 65363) // >
	{
		(*st)->player.rigth = true;
		ft_move_player(st);
	}
	return (0);
}
