/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:47:03 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/30 20:15:48 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	if (haystack == NULL)
		n_len = ft_strlen(haystack);
	n_len = ft_strlen(needle);
	if (haystack == needle && haystack)
		return ((char *)haystack);
	i = 0;
	while (i + n_len <= len && haystack[i])
	{
		j = 0;
		while (j < n_len && haystack[i + j] == needle[j])
		{
			if (j + 1 == n_len)
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
/* 
int main(void)
{
	char a[] = "Hello  World";
	char b[] = "World";
	char *p;
	char *p1;
	int i = 0;	
	 
	p = ft_strnstr("", "tu", -1);
	p1 = strnstr("", "tu", -1);
	
		printf("%s",p);
		printf("%s",p1);



} 
*/
