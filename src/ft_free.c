#include "../include/cub3D.h"


void ft_free_two_dimensional_array(char **map)
{
    int i;

    i = 0;

    if (!map)
        return ;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void ft_free_st(t_cube **st)
{

    if ((*st)->c_map)
        ft_free_two_dimensional_array((*st)->c_map);
    if ((*st)->normalayz_map)
        ft_free_two_dimensional_array((*st)->normalayz_map);
    if ((*st)->map_for_flood)
        ft_free_two_dimensional_array((*st)->map_for_flood);

    free((*st)->west);
    free((*st)->south);
    free((*st)->north);
    free((*st)->east);

    (*st)->c_map = NULL;
    (*st)->normalayz_map = NULL;
    (*st)->map_for_flood = NULL;
    (*st)->west = NULL;
    (*st)->south = NULL;
    (*st)->north = NULL;
    (*st)->east = NULL;
    free(*st);
    *st = NULL;
}