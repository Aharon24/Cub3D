/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:44:53 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/23 15:30:33 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <ctype.h>
//#include <stdio.h>
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
int main(void)
{	
	char a = 'a';
	char c = '2';

	printf("my a %d\n",ft_isalpha(97));
	printf("my 2 %d\n",ft_isalpha(98)); 
	printf("Or a %d\n",isalpha(97));
	printf("Or 2 %d\n",isalpha(98));
}*/
