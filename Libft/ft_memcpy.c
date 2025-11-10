/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:22:55 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/27 20:28:22 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*dest1;
	const unsigned char		*src1;

	i = 0;
	if (dst == NULL && src == NULL && n > 0)
		return (NULL);
	src1 = src;
	dest1 = dst;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dst);
}
/*
int main(void)
{
	char a[20] = "Hello";
	char b[20] = "hello";
	
	ft_memcpy(a,"aaaHELLO YEREVAN",20);
	memcpy(b,"aaaHELLO YEREVAN",20);
	printf("My:%s\n",a);
	printf("Or:%s\n",b);
}*/
