/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:30:27 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/26 15:52:52 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include  <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t					i;
	unsigned char			*dest;
	const unsigned char		*src1;

	dest = (unsigned char *)dst;
	src1 = (const unsigned char *)src;
	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src1[i] != '\0' && dstsize != 0)
	{
		dest[i] = src1[i];
		i++;
	}
	dest[i] = '\0';
	while (src1[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
int main(void)
{
	char d[20];
	char a[20];
	char *str = "Hello, world";
	int f;
	int t;

	f = ft_strlcpy(d,str,12);                                    
	t =  strlcpy(a,str,12);
	printf("Or:%s len = %d\n",a,t);
	printf("My:%s len = %d \n",d,f);
}*/
