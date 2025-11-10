/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:52:13 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/26 12:42:06 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s1[i] = 0;
		i++;
	}
}
/*
int main(void)
{
	char a[15] = "hay how are you";
	bzero(a,14);
	printf("OR:%s\n",a);
	char b[15] = "hay how are you";
	ft_bzero(b,14);
	printf("My:%s\n",b);
	
}*/
