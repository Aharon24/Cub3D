/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:45:44 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/25 15:00:52 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c +32);
	return (c);
}
/*
int main(void)
{
	char a = '9';
	char b = 'A';
	printf("MY:%c\n",ft_tolower(a));
	printf("OR:%c\n",tolower(a));
	printf("MY:%c\n",ft_tolower(b));
	printf("OR:%c\n",tolower(b));
}*/
