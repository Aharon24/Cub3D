/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:03:54 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/31 19:35:49 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	m;

	i = 0;
	num = 0;
	m = 1;
	while (((str[i] >= 9 && str[i] <= 13) || (str[i] == 32)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10;
		num = num + (str[i] - 48);
		i++;
	}
	return (num * m);
}
/*
int main(void)
{
	char a[] = "-1234sd";
	char b[] = "12345sb";
	int a1 = ft_atoi(a);
	int b1 = ft_atoi(b);
	printf("-1234sd = %d\n",a1);
	printf(" 12345sb = %d",b1);
	printf(" 12345sb = %d",b1);
	printf(" 12345sb = %d",b1);
	
}*/
