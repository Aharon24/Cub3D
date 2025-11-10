/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:04:09 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/30 20:53:45 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
		return (dst);
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src && dst < src + len)
	{
		while (len != 0)
		{
			len--;
			*(unsigned char *)(dst + len) = *(const unsigned char *)(src + len);
		}
	}
	else
	{
		while (i < len)
		{
			*(unsigned char *)(dst + i) = *(const unsigned char *)(src + i);
			i++;
		}
	}
	return (dst);
}
/*
int main(void)
{
	char src[] = "Lorem ipsum dolor sit amet";
	char src1[] = "Lorem ipsum dolor sit amet";
	char *dest;
	char *dest1;

	dest  = src + 1;
	dest1 = src + 1;
	ft_memmove(dest,src,8);
	memmove(dest1,src1,8);
	printf("My:%s\n",dest);
	printf("Or:%s\n",dest1);
}*/
