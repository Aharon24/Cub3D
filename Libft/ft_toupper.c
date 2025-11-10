/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:51:14 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/25 13:54:04 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
/*
int main(void)
{
	char a = '9';
	char b = 'a';
	printf("MY:%c\n",ft_toupper(a));
	printf("OR:%c\n",toupper(a));
	printf("MY:%c\n",ft_toupper(b));
	printf("OR:%c\n",toupper(b));
}*/
