/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:41:38 by ahapetro          #+#    #+#             */
/*   Updated: 2025/12/25 14:41:39 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_chek_file(int fd)
{
	if (fd == -1)
	{
		printf("Error\n");
		printf("Permission denied file dont have Permission for reding\n");
		close(fd);
		return (-1);
	}
	return (0);
}

int	ft_strncmp(char *str, char *str1, int n)
{
	int	i;

	if (!str || !str1)
		return (2);
	i = 0;
	while (i < n && str[i] && str1[i] && str[i] == str1[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)str[i] - (unsigned char)str1[i]);
}

int	ft_validation(char *argv)
{
	int	ch;

	ch = 0;
	if (!argv)
		return (0);
	ch = ft_strncmp(&argv[ft_strlen(argv) - 4], ".cub", 4);
	if (ch == 2)
	{
		printf("Error\n");
		printf ("!str || ! str1\n");
	}
	else if (ch != 0)
	{
		printf("Error\n");
		printf("Wrong file\n");
		return (1);
	}
	return (0);
}

int	ft_chesk_color_number(int a, int b, int c)
{
	if (a < 0 || a > 255)
	{
		printf("Error\n");
		printf("wrong number it must be in size 0-255 -> (%d)\n", a);
		return (-1);
	}
	if (b < 0 || b > 255)
	{
		printf("Error\n");
		printf("wrong number it must be in size 0-255 -> (%d)\n", b);
		return (-1);
	}
	if (c < 0 || c > 255)
	{
		printf("Error\n");
		printf("wrong number it must be in size 0-255 -> (%d)\n", c);
		return (-1);
	}
	return (0);
}

int	ft_check_path_count(t_cube **st)
{
	if ((*st)->path_xpm.ceiling != 1)
		return (1);
	else if ((*st)->path_xpm.floor != 1)
		return (1);
	else if ((*st)->path_xpm.no != 1)
		return (1);
	else if ((*st)->path_xpm.so != 1)
		return (1);
	else if ((*st)->path_xpm.we != 1)
		return (1);
	else if ((*st)->path_xpm.ea != 1)
		return (1);
	else
		return (0);
}
