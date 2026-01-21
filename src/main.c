/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:41:41 by ahapetro          #+#    #+#             */
/*   Updated: 2026/01/11 19:19:33 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	main(int ac, char *argv[])
{
	t_cube	*stt;
	int		fd;

	fd = 0;
	stt = NULL;
	if (ac != 2)
		return (ft_exit_main());
	else
	{
		if (ft_validation(argv[1]) != 0)
			return (1);
	}
	stt = ft_start_work(argv[1], fd);
	if (stt == NULL)
	{
		ft_free_st(&stt);
		return (1);
	}
	if (stt)
		ft_game(&stt);
	ft_free_st(&stt);
	return (0);
}
