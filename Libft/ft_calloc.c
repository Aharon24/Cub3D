/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:37:58 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/31 19:38:04 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*h;
	size_t			i;

	i = 0;
	if (count == 0 || size == 0)
		return (malloc(1));
	h = malloc(count * size);
	if (!h)
		return (NULL);
	while (i < count * size)
	{
		h[i] = 0;
		i++;
	}
	return (h);
}
/*
int main(void)
{
    int i;
    i = 9;
    //char *str = (char *)ft_calloc(10,sizeof(char));
    char *str2 = (char *)calloc(10,0);
    
    while(i < 10)    
    {
       // printf("My:%c\n",str[i]);
        printf("Or:%c\n",str2[i]);
        i++;
    }  
}*/