/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:21:39 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/24 13:25:52 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
int main(void)
{
	printf("My hello :%zu\n",ft_strlen("hello"));
	printf("My Barev :%zu\n",ft_strlen("barev"));
	printf("My a :%zu\n",ft_strlen("a"));

	printf("Or hello :%zu\n",strlen("hello"));
	printf("Or Barev :%zu\n",strlen("Barev"));
	printf("Or  a:%zu\n",strlen("a"));
}*/
