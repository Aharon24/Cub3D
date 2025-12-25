/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_for_moving.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:41:03 by ahapetro          #+#    #+#             */
/*   Updated: 2025/12/25 14:41:04 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_valit_line_for_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == '\n' && line[i + 1] == '\0') || line[i] == 32)
			i++;
		else if (line[i] == '1' || line[i] == '0')
			i++;
		else if (line[i] == 'S' || line[i] == 'N'
			|| line[i] == 'W' || line[i] == 'E')
			i++;
		else if (line[i] == 's' || line[i] == 'n'
			|| line[i] == 'w' || line[i] == 'e')
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_map_create_for_moveing(char *line, int i, t_cube **st, char **b)
{
	static int	len;
	static int	l;

	if ((*st)->norm_dor == 0)
		ft_zero(&len, &l);
	if ((*st)->norm_dor == 0)
	{
		(*st)->normalayz_map = NULL;
		len = 0;
		while (b[i])
		{
			i++;
			len++;
		}
		(*st)->normalayz_map = malloc(sizeof(char *) * (len + 1));
		(*st)->norm_dor = 1;
	}
	if (ft_valit_line_for_map(line) == 1)
		(*st)->map_valid = 1;
	else if (l < len)
	{
		(*st)->normalayz_map[l] = ft_strdup_no_newline(line);
		l++;
	}
	(*st)->normalayz_map[l] = NULL;
}

void	ft_flood_fill(t_cube **st, int rows, int x, int y)
{
	int	cols;

	if (x < 0 || x >= rows)
		return ;
	cols = ft_strlen((*st)->map_for_flood[x]);
	if (y < 0 || y >= cols)
		return ;
	if ((*st)->map_for_flood[x][y] != '0'
		&& ft_chesk_x_y((*st)->map_for_flood[x][y]))
		return ;
	(*st)->map_for_flood[x][y] = 'V';
	ft_flood_fill(st, rows, x + 1, y);
	ft_flood_fill(st, rows, x - 1, y);
	ft_flood_fill(st, rows, x, y + 1);
	ft_flood_fill(st, rows, x, y - 1);
}

void	ft_set_map(char **map, t_cube **st)
{
	int	i;

	i = 0;
	while (map[i])
	{
		(*st)->map_for_flood[i] = ft_strdup(map[i]);
		i++;
	}
	(*st)->map_for_flood[i] = NULL;
}

int	ft_chekc_norm_map_m(char **map, t_cube **st)
{
	int	x;
	int	i;	

	x = 0;
	while (map[x])
		x++;
	(*st)->map_for_flood = NULL;
	(*st)->map_for_flood = malloc(sizeof(char *) * (x + 1));
	ft_set_map(map, st);
	i = 0;
	if (ft_luck_map(st) == 0)
		return (1);
	ft_find_player_point(st, (*st)->normalayz_map);
	ft_flood_fill(st, x, (*st)->player_x, (*st)->player_y);
	i = 0;
	if (ft_flood_file_chesk((*st)->map_for_flood) == 1)
		return (1);
	return (0);
}
