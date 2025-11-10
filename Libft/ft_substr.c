/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:39:44 by ahapetro          #+#    #+#             */
/*   Updated: 2025/02/01 15:40:35 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	j;
	size_t	s_len;

	j = 0;
	s_len = ft_strlen(s);
	if (s_len - start <= len)
		len = s_len - start;
	if ((start >= s_len || s_len == 0))
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
		return (s1);
	}
	s1 = (char *)malloc((len + 1) * sizeof(char));
	if (!s1)
		return (NULL);
	while (j < len)
	{
		s1[j] = s[start + j];
		j++;
	}
	s1[j] = '\0';
	return (s1);
}
// int main(void)
// {
// 	char a[] = "HEllo";
// 	char *b;
// 	b = ft_substr(a,10,2);
// 	printf("%s",b);
// 	free(b);
// }