/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:54:38 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/27 21:19:15 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	b;

	b = (unsigned char)c;
	while (*s)
	{
		if (*s == b)
			return ((char *)s);
		s++;
	}
	if (b == '\0')
		return ((char *)s);
	return (NULL);
}
/*
int main(void)
{
	char a[] = "Hello World";
	
	printf("My: %p\n",ft_strchr(a,'\0'));
	printf("Or: %p\n",strchr(a,'\0'));
}*/	
