/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:29:47 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/23 15:30:55 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include  <stdio.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
/*
int main(void)
{
	int i;
	i= 0;	
	char a[10] = "haaa";
	char c[10] = "haaa";
	ft_memset(a,97,20);
	printf("My:%s\n",a);
	memset(c,97,20);
	printf("Or:%s\n",c);
}*/
