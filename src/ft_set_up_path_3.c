/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_up_path_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:41:16 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/16 19:31:07 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"


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

void	ft_init_xpm_one(t_cube **st)
{
	(*st)->map_for_flood = NULL;
	(*st)->normalayz_map = NULL;
	(*st)->west = NULL;
	(*st)->south = NULL;
	(*st)->north = NULL;
	(*st)->east = NULL;
	(*st)->west = ft_strdup("./Path_xpm/west.xpm");
	(*st)->south = ft_strdup("./Path_xpm/sount.xpm");
	(*st)->north = ft_strdup("./Path_xpm/north.xpm");
	(*st)->east = ft_strdup("./Path_xpm/east.xpm");
	(*st)->frst_part = 0;
	(*st)->map_valid = 0;
	(*st)->norm_dor = 0;
}
