#include "cub3D.h"

void  ft_start_work(char *str)
{
    int r;
    int fd;
    char *line;

    r = 0;
    fd = 0;

    fd = open(str,O_RDONLY);
    if (fd == -1)
    {
        printf("Error\n");
        printf("Permission denied file dont have Permission for reding\n");
        return ;
    }
    else
        line = get_next_line(fd);
    if (!line)
    {
        printf("Error\n");
        printf("Empty file\n");
        return ;
    }
    while(line)
    {
        printf("%s",line);
        line = get_next_line(fd);
    }

}