#include "../include/cub3D.h"

////???????????????????
// int ft_check_len_number(char **line)
// {
//     int i;
//     int len;

//     i = 0;
//     len = 0;
//     if (!line)
//         return (-1);
//     while (line[i])
//     {
//         len = ft_strlen(line[i]);
//         if (len == 14)
//             return (-1);
//         i++;
//     }
//     return (0);
// }
void	ft_letter(char letter, char **line, t_cube **st)
{
	if (letter == 'C')
	{
		ft_set_number(line, st, letter);
		if (ft_chesk_color_number((*st)->co.c_1,
				(*st)->co.c_2, (*st)->co.c_3) == -1)
		{
			(*st)->color_check = 1;
			return ;
		}
		else
			(*st)->path_xpm.ceiling++;
	}
	else if (letter == 'F')
	{
		ft_set_number(line, st, letter);
		if (ft_chesk_color_number((*st)->co.f_1,
				(*st)->co.f_2, (*st)->co.f_3) == -1)
		{
			(*st)->color_check = 1;
			return ;
		}
		else
			(*st)->path_xpm.floor++;
	}
}

void	ft_set_number(char **line, t_cube **st, char letter)
{
	if (letter == 'C')
	{
		(*st)->co.c_1 = ft_atoi(line[0]);
		(*st)->co.c_2 = ft_atoi(line[1]);
		(*st)->co.c_3 = ft_atoi(line[2]);
	}
	else if (letter == 'F')
	{
		(*st)->co.f_1 = ft_atoi(line[0]);
		(*st)->co.f_2 = ft_atoi(line[1]);
		(*st)->co.f_3 = ft_atoi(line[2]);
	}
}
