#include "cub3D.h"

int ft_strncmp(char *str, char *str1, int n)
{
    int i;

    i = 0;
    if (!str || !str1)
        return (2);
    while (i < n && str[i] == str1[i])
        i++;
    return (str[i] - str1[i]); 
}


int ft_validation(char *argv)
{
    int ch;
    if (!argv)
        return (0);
    ch = ft_strncmp(&argv[ft_strlen(argv) - 4], ".cub", 4);
    if (ch == 2)
    {
        printf("Error\n");
        printf ("!str || ! str1\n");
    }
    else if( ch != 0)
    {
        printf("Error\n");
        printf("Wrong file\n");
    }
    return (0);
}