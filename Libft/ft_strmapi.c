/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:45:50 by ahapetro          #+#    #+#             */
/*   Updated: 2025/02/05 14:52:32 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
		len++;
	new = (char *)malloc(len + 1 * sizeof(char));
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[len] = '\0';
	return (new);
}

// int mian(void)
// {
// 	char a[] = "hello";
// 	char  *b;
// 	b = ft_strmapi(a,ft_);
// }