/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:08:53 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/23 15:26:31 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int main(void)
{
	char a = 'a';
	char c = '2';

	printf("my 0  a %d\n",ft_isdigit(a));
	printf("my 1  2 %d\n",ft_isdigit(c));
	printf("Or a %d\n",isdigit(a));
	printf("Or 2 %d\n",isdigit(c));
}*/	
