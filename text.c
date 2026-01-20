#include "../minilibx-linux/mlx.h"

typedef struct s_game
{
    void *mlx;
    void *win;
    void *img;
    int win_x;
    int win_y;
    char *data;
    int bpp;
    int size_len;
    int endian;
}   t_game;

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIDTH= || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->s_l + x * (game->bpp / 8);

	if (game->bpp == 32)
	{
		unsigned int *dst = (unsigned int *)(game->data + index);
		*dst = (unsigned int)color;
	}
	else if (game->bpp == 24)
	{
		game->data[index] = color & 0xFF;
		game->data[index + 1] = (color >> 8) & 0xFF;
		game->data[index + 2] = (color >> 16) & 0xFF;
	}
	// для других bpp — можно добавить обработку
}



int get_color(int r, int g, int b)
{
    return (r << 16) | (g << 8) | b;
}

int main()
{
    t_game game;

    // Настройка MiniLibX
    game.mlx = mlx_init();
    game.win_x = 400;
    game.win_y = 300;
    game.win = mlx_new_window(game.mlx, game.win_x, game.win_y, "Test");
    game.img = mlx_new_image(game.mlx, game.win_x, game.win_y);
    game.data = mlx_get_data_addr(game.img, &game.bpp, &game.size_len, &game.endian);

    // Получаем цвет из R,G,B
    int color = get_color(56, 100, 190); // 0x3864BE

    // Рисуем пиксель в центре окна
    put_pixel(game.win_x/2, game.win_y/2, color, &game);

    // Показываем изображение
    mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);

    mlx_loop(game.mlx);
    return 0;
}



// int	ft_draw_loop(t_game *game)
// {
// 	float		fraction;
// 	float		start_x;
// 	int			i;
// 	t_player	*player;
// 	player = &game->player;
// 	ft_move_player(game);
// 	ft_clear_image(game);
// 	ft_draw_floor_cealing(game);
// 	fraction = PI / 3 / WIDTH;
// 	start_x = game->player.angle - PI / 6;
// 	//ft_draw_map_four(game);
// 	i = 0;
// 	while (i < WIDTH)
// 	{
// 		ft_draw_line(player, game, start_x, i);
// 		start_x += fraction;
// 		i++;
// 	}
// 	ft_draw_map(game);
// 	ft_draw_square(player->x / 4, player->y / 4, 3, 0x00FF00, game);
// 	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
// 	return (0);
//}

// void ft_draw_square(int x, int y, int size, int color, t_game *game)
// {
//     int i, j;
//     i = 0;
//     while (i < size)
//     {
//         j = 0;
//         while (j < size)
//         {
//             put_pixel(x + j, y + i, color, game);
//             j++;
//         }
//         i++;
//     }
// }

// int ft_get_wall_pixel(t_game *game, t_tex *tex, int y)
// {
//     int tex_x;
//     int tex_y;
//     float wall_height;

//     tex_x = (int)(game->ray_x * (float)tex->width);
//     if ((game->hit_vertical == 1 && cos(game->player.angle) < 0) || 
//         (game->hit_vertical == 0 && sin(game->player.angle) > 0))
//         tex_x = tex->width - tex_x - 1;
//     wall_height = (int)(B * HEIGHT / (game->player.dist));
//     int relative_y = y - game->start_y;
//     tex_y = (int)(relative_y * (float)tex->height / wall_height);
//     if (tex_y < 0) tex_y = 0;
//     if (tex_y >= tex->height) tex_y = tex->height - 1;
//     if (tex_x < 0) tex_x = 0;
//     if (tex_x >= tex->width) tex_x = tex->width - 1;

//     return (ft_get_tex_pixel(tex, tex_x, tex_y));
// }