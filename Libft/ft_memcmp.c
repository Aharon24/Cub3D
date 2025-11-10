/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:32:03 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/30 21:00:23 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] == p2[i])
			i++;
		else
			return (p1[i] - p2[i]);
	}
	return (0);
}
/*
int main(void)
{	
	char a[] = "hell";
	char b[] = "helll";
	int	c;
	c = ft_memcmp(a,b,5);
	printf("%d",c);
}*/
