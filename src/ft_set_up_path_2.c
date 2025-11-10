#include "cub3D.h"

void ft_split_check(char *line)
{
    char **arr;
    int i;

    i = 0;
    arr = ft_split(line, ' ');
    while(arr[i])
    {
        printf("arr[%d] -> %s\n",i, arr[i]);
        i++;
    }

}