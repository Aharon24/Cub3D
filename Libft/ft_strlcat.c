/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:26:50 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/27 20:00:07 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	size_t	s;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	if (i >= dstsize)
		return (dstsize + ft_strlen(src));
	if (dstsize == 0)
		return (ft_strlen(src));
	s = 0;
	while (i < dstsize - 1 && src[s] != '\0')
	{
		dst[i] = src[s];
		s++;
		i++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
/*
int main(void)
{
	char a[20] = "Hello, World!";
	char ab [20] = "Hello, World!";
	char b[] = "How are you?";

	size_t len = ft_strlcat(a,b,sizeof(a));
	size_t len1 = strlcat(ab,b,sizeof(ab));
	printf("len = %zu My: %s\n",len,a);
	printf("len = %zu Or: %s\n",len1,ab);
}*/
