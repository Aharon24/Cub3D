/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:28:31 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/26 12:43:30 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((ft_isdigit(c) == 1) || (ft_isalpha(c) == 1))
		return (1);
	return (0);
}
/*
int main(void)
{
	char a = 'a';
	char b = '2';
	char c = 'Z';
	
	printf("My a %d\n",ft_isalnum(a));
	printf("My 2 %d\n",ft_isalnum(b));
	printf("My Z %d\n",ft_isalnum(c));
	printf("Or a %d\n",isalnum(a));
	printf("Or 2 %d\n",isalnum(b));
	printf("Or Z %d\n",isalnum(c));

	printf("My a %d\n",ft_isalnum(12));
	printf("MY a %d\n",ft_isalnum(300));
	printf("Or a %d\n",isalnum(12));
	printf("Or a %d\n",isalnum(300));
}*/
