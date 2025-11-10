#include "cub3D.h"

void    ft_split_check(char *line, t_cube **st)
{
    char **arr;
    int i;

    i = 0;
    arr = ft_split(line, ' ');

    while(arr[i])
    {
        if (arr[i][0] == 'C' || arr[i][0] == 'F')
            ft_check_floor_ceiling(arr[i]);
        else if (ft_strncmp(arr[i],"NO",2) == 0)
                ft_check_line(arr[1],*st);
        else if (ft_strncmp(arr[i],"SO",2) == 0)
                ft_check_line(arr[1],*st);
        else if (ft_strncmp(arr[i],"WE",2) == 0)
                ft_check_line(arr[1],*st);
        else if (ft_strncmp(arr[i],"EA",2) == 0)
                ft_check_line(arr[1],*st);
        else if (ft_check_map_number(arr[i]) == 1)
        {

        }
        else
        {
               // ft_error_file_path();
                return ;
                ///free map **
        }
        printf("arr[%d] ->%s\n",i, arr[i]);
        i++;
    }
    ///free(arr);
    ///free(line);
}


void    ft_check_floor_ceiling(char *str)
{
    printf("F or C %s\n",str);
}


ft_check_map_number
