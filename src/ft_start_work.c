#include "../include/cub3D.h"

void	ft_start_work(char *str)
{
	int		fd;
	char	*line;
	t_cube	*st;

	line = NULL;
	st = NULL;
	fd = 0;
	fd = open(str, O_RDONLY);
	if (ft_chek_file(fd) == -1)
	{
		close(fd);
		return ;
	}
	st = ft_create_struct(fd, st);
	close(fd);
	if (st == NULL)
		return ;
	fd = open(str, O_RDONLY);
	ft_init_xpm(&st);
	st = ft_create_map(&st, line, fd);
	if (st == NULL)
	{
		printf("Error\n");
		printf("wrong map \n");
		close(fd);
		return ;
	}
	close(fd);
	ft_parsing_map(st->c_map, &st);
	ft_free_st(&st);
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
	{
		printf("malloc problem");
		return (NULL);
	}
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
