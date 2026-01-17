/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:41:28 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/17 14:05:18 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_chesk_point(char *line)
{
	int	i;
	int	p;

	p = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == 'S' || line[i] == 'N'
			|| line[i] == 'W' || line[i] == 'E')
			p++;
		else if (line[i] == 's' || line[i] == 'n'
			|| line[i] == 'w' || line[i] == 'e')
			p++;
		i++;
	}
	return (p);
}

int	ft_chesk_middle_line(char *line, int index)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (i == 0 && line[i] != '1' && line[i] != ' ')
		{
			printf("Error\n");
			printf("wrong line in map %s index -> %d\n", line, index);
			return (1);
		}
		else if (line[i + 1] == '\0' && line[i] != '1' && line[i] != ' ')
		{
			printf("Error\n");
			printf("wrong line in map  %s index -> %d\n", line, index);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_look_middle(char **map, int len, int p)
{
	int	i;

	i = 0;
	if (ft_chesk_point(map[i]) != 0)
	{
		printf("Error\n");
		printf("wrong map %s\n", map[i]);
		return (0);
	}
	i = 1;
	while (map[i] && i < len - 1)
	{
		p += ft_chesk_point(map[i]);
		if (ft_chesk_middle_line(map[i], i) == 0)
			i++;
		else
			return (0);
	}
	if (p != 1)
	{
		ft_error_validation_two(p);
		return (0);
	}
	return (1);
}

int	ft_one(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			i++;
		else
		{
			printf("Error\n");
			printf("wrong map start or end not close %s", str);
			return (0);
		}
	}
	return (1);
}

int	ft_luck_map(t_cube **st)
{
	int	i;
	int	j;
	int	len;
	int	p;

	p = 0;
	i = 0;
	j = 0;
	len = 0;
	while ((*st)->normalayz_map[len])
		len++;
	if ((ft_one((*st)->normalayz_map[len - 1]))
		&& (ft_one((*st)->normalayz_map[i]))
		&& (ft_look_middle((*st)->normalayz_map, len, p)));
	else
		return (0);
	return (1);
}
