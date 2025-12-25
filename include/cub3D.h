#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>     // read, write, close
# include <fcntl.h>      // open
# include <stdlib.h>     // malloc, free, exit
# include <stdio.h>      // printf, perror
# include <string.h>     // strerror
# include <sys/time.h>
# include <math.h>       // sin, cos, sqrt, etc.
# include "../get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"
//#include "mlx.h"        // MiniLibX

typedef struct s_map {
    int rows;
    int cols;
}   t_map;

typedef struct s_game
{
	void *mlx;
	void *win;
	void *img;
	int win_x;
	int win_y;
	char *data;
	int bpp;
	int s_l;
	int e_d;
	int f_color;
	int c_color;
}	t_game;

typedef struct s_color
{
	int	f_1;
	int	f_2;
	int	f_3;
	int	c_1;
	int	c_2;
	int	c_3;
}	t_color;

typedef struct s_path
{
	int		no;
	int		so;
	int		we;
	int		ea;
	int		floor;
	int		ceiling;
}	t_path;

typedef struct cub3D
{
	t_path	path_xpm;
	t_color	co;
	t_map	map_s;
	t_game 	g;
	int 	player_x;
	int 	player_y;
	int		secont_part;
	int		frst_part;
	int		start_creating_map;
	int		color_check;
	int		path_check;
	char	**c_map;
	char	**normalayz_map;
	char 	**map_for_flood;
	int		norm_dor;
	int		map_len;
	int		main_map_len;
	int		map_valid;
	int		main_map_check;
	int		c;
	char	*west;
	char	*south;
	char	*north;
	char	*east;
	int		f_pix_x;
	int		c_pix_x;
}	t_cube;

//	ft_free.c

void	ft_free_st(t_cube **st);
void	ft_free_two_dimensional_array(char **map);
void	ft_free_arr_map(t_cube **st);

/// ft_error.c

int		ft_error(int subject, int i);
int		ft_error_file_path(void);
t_cube	*ft_st_null(int fd);
void	ft_error_validation_two(int player);
t_cube	*ft_error_start_work(void);

//	ft_set_up_path_3.c

void	ft_set_number(char **line, t_cube **st, char letter);
void	ft_letter(char letter, char **line, t_cube **st);
void	ft_init_xpm_one(t_cube **st);


//	ft_set_up_path_2.c

void	ft_split_check(char *line, t_cube **st);
int		ft_check_valid_map(char *str, t_cube *st);
int		ft_check_f_c(char **line, t_cube **st);
void	ft_check_floor_ceiling(t_cube **st, char *str, char letter);
int		ft_count_comma(char *str);

//	ft_set_up_path.c
void	ft_set_up_path(t_cube **st, int n);
void	ft_init_xpm(t_cube **st);
void	ft_create_arr_path(char *str, t_cube **st);
int		ft_count_without_white_space(char *str);
void	ft_make_line(char **line, char *s, int i, int j);

//  ft_parsing.c

int		ft_check_line(char *str, t_cube **st);
t_cube	*ft_parsing_map(char **map, t_cube **st);
int		ft_count_line(char **map, t_cube **st, int i);
int		ft_empty(char *str);
void	ft_one_for_parsing(t_cube **st);

//  ft_validation.c

int		ft_strncmp(char *str, char *str1, int n);
int		ft_validation(char *argv);
int		ft_chek_file(int fd);
int		ft_chesk_color_number(int a, int b, int c);
int		ft_check_path_count(t_cube **st);

//	ft_validation_2.c

int		ft_luck_map(t_cube **st);
int		ft_one(char *str);
void	ft_look_middle(char **map, int len);
int		ft_chesk_middle_line(char *line, int index);
int		ft_chesk_point(char *line);

//	ft_validation_3.c

int		ft_chesk_x_y(char c);
void	ft_find_player_point(t_cube **st, char **map);
int		ft_flood_file_chesk(char **map);
char 	*ft_strdup_no_newline(const char *line);
int		ft_chesk_side(char **map, int x, int y, int len_x);

//	ft_validation_4.c

int		ft_empty_chesk(char **map);

//  ft_start_work.c
t_cube 	*ft_start_work(char *str);
t_cube	*ft_create_struct(int fd, t_cube *st);
t_cube	*ft_create_map(t_cube **st, char *line, int fd);

//	ft_map_for_moving.c
void 	ft_map_create_for_moveing(char *line,int i, t_cube **st, char **b);
int		ft_valit_line_for_map(char * line);
void	ft_flood_fill(t_cube **st, int rows, int x, int y);
int		ft_chekc_norm_map_m(char **map,t_cube **st);
void	ft_set_map(char **map, t_cube **st);

//	ft_map_for_moving_1.c
void ft_zero(int *len , int *l);


//	ft_game.c
void	ft_game(t_cube **stt);
void	ft_create_window(t_cube **stt);


//	ft_draw.c
void	put_pixel(int x, int y, int color, t_game *game);
int		get_color(int r, int g, int b);
void	ft_draw_floor_cealing(t_cube **stt);
void    ft_draw_part(t_cube **stt, int color, char c);
void    ft_draw_c(int color, t_cube **stt, int i, int j);
void    ft_draw_f(int color, t_cube **stt, int i, int j);

#endif