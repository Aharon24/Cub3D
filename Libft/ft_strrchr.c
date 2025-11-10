/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:18:28 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/27 21:48:34 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	a;
	int				i;

	a = (unsigned char)c;
	i = ft_strlen (s);
	if (a == '\0')
		return ((char *)(s + i));
	while (i > 0)
	{
		if (*(s + i - 1) == a)
			return ((char *)(s + i - 1));
		i--;
	}
	return (NULL);
}
/*
int main(void)
{
	char a[] = "Hello World";

	printf("My: %p\n",ft_strrchr(a,'o'));
	printf("Or: %p\n",strrchr(a,'o'));
}*/
