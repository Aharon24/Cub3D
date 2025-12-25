/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:41:35 by ahapetro          #+#    #+#             */
/*   Updated: 2025/12/25 14:41:36 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_empty_chesk(char **map)
{
	int	i;
	int	len;
	int	e;

	e = 0;
	len = 0;
	i = 0;
	while (map[len])
		len++;
	while (map[i])
	{
		if (ft_empty(map[i]) == 1)
			e++;
		i++;
	}
	if (e == len)
	{
		printf("Error\n");
		printf("wrong map empty and new line \n");
		return (1);
	}
	return (0);
}
