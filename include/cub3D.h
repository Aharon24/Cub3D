
# ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>     // read, write, close
# include <fcntl.h>      // open
# include <stdlib.h>     // malloc, free, exit
# include <stdio.h>      // printf, perror
# include <string.h>     // strerror
# include <sys/time.h>   // gettimeofday
# include <math.h>       // sin, cos, sqrt, etc.
# include  "../get_next_line/get_next_line.h"
# include  "../minilibx-linux/mlx.h"
# include  "../Libft/libft.h"
//#include "mlx.h"        // MiniLibX

typedef struct path
{
	int no;
	int so;
	int we;
	int ea;
	int floor;
	int ceiling;
}	t_path;


typedef struct cub3D
{
	t_path Path_xpm;
	char **c_map;
	char **Normalayz_map;
	int   map_len;
	
}   t_cube;

//	ft_set_up_path_2.c

void	ft_split_check(char *line, t_cube **st);
void    ft_check_floor_ceiling(char *str);



//	ft_set_up_path.c
void	ft_set_up_path(t_cube *st, int n);
void	ft_init_xpm(t_cube *st);
void	ft_create_arr_path(char *str, t_cube **st);
int		ft_count_without_white_space(char *str);
void    ft_make_line(char **line, char *str);



//  ft_parsing.c

t_cube	*ft_parsing_map(char **map, t_cube **st);
int		ft_count_line(char **map, t_cube **st);
int		ft_empty(char *str);
int		ft_check_line(char *str, t_cube *st);
int		ft_error_file_path(void);

//  ft_validation.c

int		ft_strncmp(char *str, char *str1, int n);
int		ft_validation(char *argv);
int		ft_chek_file(int fd);

//  ft_start_work.c

void    ft_start_work(char *str);
t_cube	*ft_create_struct(int fd, t_cube *st);
t_cube  *ft_create_map(t_cube *st, char *line, int fd);


#endif