/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:20:40 by ahapetro          #+#    #+#             */
/*   Updated: 2025/02/03 17:06:21 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, char const	*se)
{
	while (*se)
	{
		if (*se == c)
			return (1);
		se++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*new;
	int		len;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1) - 1;
	start = 0;
	while (s1[start] && ft_check(s1[start], set))
		start++;
	while (end >= start && ft_check(s1[end], set))
		end--;
	len = end - start + 1;
	if (len <= 0)
		return (ft_strdup(""));
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1 + start, len + 1);
	return (new);
}
// int main(void)
// {
//     char a[] = "  HeLLooo  ";
//     char b[] = " ";
//     printf("%s",ft_strtrim(a,b));
// }
