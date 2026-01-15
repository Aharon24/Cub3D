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

void put_pixel(int x, int y, int color, t_game *game)
{
    int index;

    if (x >= game->win_x || y >= game->win_y || x < 0 || y < 0)
        return;
    index = y * game->size_len + x * game->bpp / 8;
    game->data[index] = color & 0xff;
    game->data[index + 1] = (color >> 8) & 0xff;
    game->data[index + 2] = (color >> 16) & 0xff;
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
