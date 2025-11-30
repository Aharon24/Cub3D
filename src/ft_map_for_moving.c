#include "../include/cub3D.h"

int	ft_valit_line_for_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' || line[i] == 32)
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
	int			len;
	static int	l;

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
		(*st)->normalayz_map[l] = ft_strdup(line);
		l++;
	}
	(*st)->normalayz_map[l] = NULL;
}
