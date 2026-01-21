/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_up_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:41:20 by ahapetro          #+#    #+#             */
/*   Updated: 2025/12/25 14:41:21 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_create_arr_path(char *str, t_cube **st)
{
	char	*line;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = 0;
	len = ft_count_without_white_space(str);
	line = malloc(sizeof(char) * (len + 2));
	ft_make_line(&line, str, i, j);
	ft_split_check(line, st);
	free(line);
}

void	ft_make_line(char **line, char *s, int i, int j)
{
	int	c;

	c = 0;
	while (s[i])
	{
		if ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
			i++;
		else
		{
			(*line)[j] = s[i];
			if (((s[i + 1] >= 9 && s[i + 1] <= 13) || s[i + 1] == 32) && c == 0)
			{
				if (s[i + 2] == '\0')
					c = 1;
				if (s[i + 2] != '\0')
				{
					(*line)[j + 1] = s[i + 1];
					j++;
				}
			}
			j++;
			i++;
		}
	}
	(*line)[j] = '\0';
}

int	ft_count_without_white_space(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (!((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
			len++;
		i++;
	}
	return (len);
}

void	ft_set_up_path(t_cube **st, int n, char *str)
{
	if (n == 1)
	{
		if ((*st)->path_xpm.no == 0)
			(*st)->cub_n = ft_strdup(str);
		(*st)->path_xpm.no++;
	}
	else if (n == 2)
	{
		if ((*st)->path_xpm.so == 0)
			(*st)->cub_s = ft_strdup(str);
		(*st)->path_xpm.so++;
	}
	else if (n == 3)
	{
		if ((*st)->path_xpm.we == 0)
			(*st)->cub_w = ft_strdup(str);
		(*st)->path_xpm.we++;
	}
	else if (n == 4)
	{
		if ((*st)->path_xpm.ea == 0)
			(*st)->cub_e = ft_strdup(str);
		(*st)->path_xpm.ea++;
	}
}

void	ft_init_xpm(t_cube **st)
{
	(*st)->path_xpm.floor = 0;
	(*st)->path_xpm.ceiling = 0;
	(*st)->path_xpm.no = 0;
	(*st)->path_xpm.so = 0;
	(*st)->path_xpm.we = 0;
	(*st)->path_xpm.ea = 0;
	(*st)->start_creating_map = 0;
	(*st)->main_map_len = 0;
	(*st)->c = 0;
	(*st)->main_map_check = 0;
	(*st)->color_check = 0;
	(*st)->secont_part = 0;
	(*st)->path_check = 0;
	(*st)->path_xpm.floor = 0;
	(*st)->path_xpm.ceiling = 0;
	(*st)->cub_w = NULL;
	(*st)->cub_s = NULL;
	(*st)->cub_e = NULL;
	(*st)->cub_n = NULL;
	ft_init_xpm_one(st);
}
