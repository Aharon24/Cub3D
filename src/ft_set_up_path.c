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
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else
		{
			i++;
			len++;
		}
	}
	return (len);
}

void	ft_set_up_path(t_cube **st, int n)
{
	if (n == 1)
		(*st)->path_xpm.no++;
	else if (n == 2)
		(*st)->path_xpm.so++;
	else if (n == 3)
		(*st)->path_xpm.we++;
	else if (n == 4)
		(*st)->path_xpm.ea++;
}

void	ft_init_xpm(t_cube *st)
{
	st->path_xpm.floor = 0;
	st->path_xpm.ceiling = 0;
	st->path_xpm.no = 0;
	st->path_xpm.so = 0;
	st->path_xpm.we = 0;
	st->path_xpm.ea = 0;
	st->start_creating_map = 0;
	st->main_map_len = 0;
	st->c = 0;
	st->main_map_check = 0;
	st->color_check = 0;
	st->secont_part = 0;
	st->path_check = 0;
	st->path_xpm.floor = 0;
	st->path_xpm.ceiling = 0;
	st->west = ft_strdup("./Path_xpm/west.xpm");
	st->south = ft_strdup("./Path_xpm/sount.xpm");
	st->north = ft_strdup("./Path_xpm/north.xpm");
	st->east = ft_strdup("./Path_xpm/east.xpm");
	st->frst_part = 0;
	st->map_valid = 0;
}
