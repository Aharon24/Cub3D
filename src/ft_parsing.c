#include "cub3D.h"

t_cube   *ft_parsing_map(char **map, t_cube *st)
{
    ft_init_xpm(st);
    if (ft_count_line(map,st) == -1)
        return (NULL);
    return (st);
}

int  ft_count_line(char **map, t_cube *st)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(map[i])
    {
        if (ft_empty(map[i]) == 1)
        {
            //printf("empty %d \n",i);
            i++;
        }
        else
        {
          //  printf("line %d\n",i);
            ft_create_arr_path(map[i]);
            if (ft_check_line(map[i], st) == -1)
            {
                ft_error_file_path();
                return (-1);
                ///free map **
            }
            count++;
            i++;
        }
        //ft_chesk_n_s_w_e()
    }
    return (0);
}


int ft_check_line(char *str, t_cube *st)
{
    if (ft_strncmp(str,"path_to_the_north_texture",26) == 0)
        ft_set_up_path(st,1);
    else if (ft_strncmp(str, "path_to_the_south_texture",25) == 0)
        ft_set_up_path(st,2);
    else if (ft_strncmp(str,"path_to_the_west_texture",24) == 0)
        ft_set_up_path(st,3);
    else if (ft_strncmp(str,"path_to_the_east_texture",24) == 0)
        ft_set_up_path(st,4);
    else
    {
        printf("0000\n");
        return (-1);
    }
    //esle if (t_strncmp(str,"path_to_the_north_texture",26) != 0)
   // esle if(t_strncmp(str,"path_to_the_north_texture",26) != 0)
    // else
    // {

    // }
    return (0);
}

int ft_empty(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
            i++;
        else
            return (0);
    }
    return (1);
}

int ft_error_file_path(void)
{
    printf("Error\n");
    printf("wrong path in map w_s_n_e \n");
    return (-1);
} 