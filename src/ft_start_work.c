/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_work.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:12:50 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/11 19:17:52 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_cube	*ft_start_work(char *str, int fd)
{
	char	*line;
	t_cube	*st;

	line = NULL;
	st = NULL;
	fd = open(str, O_RDONLY);
	if (ft_chek_file(fd) == -1)
		return (NULL);
	st = ft_create_struct(fd, st);
	close(fd);
	if (st == NULL)
		return (NULL);
	fd = open(str, O_RDONLY);
	ft_init_xpm(&st);
	st = ft_create_map(&st, line, fd);
	if (st == NULL)
		return (ft_st_null(fd));
	close(fd);
	if (ft_parsing_map(st->c_map, &st) == NULL)
	{
		ft_free_st(&st);
		return (NULL);
	}
	return (st);
}

t_cube	*ft_create_struct(int fd, t_cube *st)
{
	int		i;
	char	*line;

	i = 1;
	line = get_next_line(fd);
	if (!line)
	{
		printf("Error\n");
		printf("Empty file\n");
		return (NULL);
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (i > 0)
	{
		st = malloc(sizeof(t_cube));
		st->c_map = malloc(sizeof(char *) * (i + 1));
	}
	if (!st->c_map)
		return (ft_error_start_work());
	return (st);
}

t_cube	*ft_create_map(t_cube **st, char *line, int fd)
{
	int	i;

	i = 0;
	line = get_next_line(fd);
	(*st)->c_map[i] = line;
	while (line)
	{
		if (line)
			(*st)->c_map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	(*st)->c_map[i] = NULL;
	if (i < 9)
	{
		ft_free_st(st);
		return (NULL);
	}
	return (*st);
}
