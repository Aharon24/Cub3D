/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 23:08:16 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/17 20:53:01 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	a  = 'a';

	printf("MY a : %d\n",ft_isascii(a));
	printf("MY 3 : %d\n",ft_isascii(3));
	printf("MY 180 : %d\n",ft_isascii(801));
	printf("MY -1 : %d\n",ft_isascii(-1));

	printf("Or a : %d\n",isascii(a));
	printf("3: %d\n",isascii(3));
	printf("Or 180 : %d\n",isascii(180));
	printf("Or -1 : %d\n",isascii(-1));
}*/	
