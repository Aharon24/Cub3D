
#ifndef CUB3D_H
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
//#include "mlx.h"        // MiniLibX


typedef struct cub3D
{
    char **c_map;
    int   map_len;
    
}   t_cube;



//ft_validation.c

int ft_strncmp(char *str, char *str1, int n);
int ft_validation(char *argv);
int ft_chek_file(int fd,char *line);

//ft_start_work.c
void    ft_start_work(char *str);
t_cube *ft_create_struct(int fd,char *line);
t_cube  *ft_create_map(t_cube *st, char *line, int fd);

#endif