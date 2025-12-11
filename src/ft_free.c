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
        map[i] = NULL;
        i++;
    }
    free(map);
}

void ft_free_st(t_cube **st)
{

    //printf("aaaa\n");
    if ((*st)->c_map)
    {
        //printf("---1\n");
        ft_free_two_dimensional_array((*st)->c_map);
        (*st)->c_map = NULL;
    }
    if ((*st)->normalayz_map)
    {
        //printf("---2\n");
        ft_free_two_dimensional_array((*st)->normalayz_map);
        (*st)->normalayz_map = NULL;
    }
    // int x;
    // x = 0;
    // while( (*st)->map_for_flood[x])
    // {
    //     printf("flood line ->       %d %s\n",x, (*st)->map_for_flood[x]);
    //     x++;
    // }
    if ((*st)->map_for_flood)
    {
       // printf("---3\n");
        ft_free_two_dimensional_array((*st)->map_for_flood);
        (*st)->map_for_flood = NULL;
    }

    if ((*st)->west)
    {
       // printf("---1 - 1\n");
        free((*st)->west);
        (*st)->west = NULL;
    }
    if((*st)->south) 
    {
        (*st)->south = NULL;
       // printf("---1 - 2\n");
        free((*st)->south);
    }
    if ((*st)->north)
    {
        (*st)->north = NULL;
       // printf("---1 - 3\n");
        free((*st)->north);
    }
    if ((*st)->east)
    {
        (*st)->east = NULL;
      //  printf("---1 - 4\n");
        free((*st)->east);
    }
    if (*st)
    {
        free(*st);
        *st = NULL;
    }
}
