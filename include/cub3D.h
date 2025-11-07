
#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>     // read, write, close
# include <fcntl.h>      // open
# include <stdlib.h>     // malloc, free, exit
# include <stdio.h>      // printf, perror
# include <string.h>     // strerror
# include <sys/time.h>   // gettimeofday
# include <math.h>       // sin, cos, sqrt, etc.
#include  "../get_next_line/get_next_line.h"
//#include "mlx.h"        // MiniLibX

//ft_validation.c

int ft_strncmp(char *str, char *str1, int n);
int ft_validation(char *argv);

//ft_start_work.c
    void    ft_start_work(char *str);
    
#endif