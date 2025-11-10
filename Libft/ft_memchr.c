/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:33:38 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/28 16:29:40 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	size_t			i;

	s1 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s1[i] == (unsigned char)c)
			return ((void *)(s1 + i));
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	char a[] = "bonjour";
	char *str;
	
char *str2	= memchr(a,'s',7);
	
	str = ft_memchr("bonjour", 0, 0);
		printf("%s\n",str2);
        printf("%s\n", str);
	return(0);	
}*/
