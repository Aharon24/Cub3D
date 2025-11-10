/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:43:18 by ahapetro          #+#    #+#             */
/*   Updated: 2025/02/05 12:09:02 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_int_min(void)
{
	char	*str;

	str = (malloc(13 * sizeof(char)));
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

static char	*ft_char(char *str, int n, int i)
{
	while (i >= 0 && n != 0)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (str);
}

static char	*ft_zero(void)
{
	char	*str;

	str = malloc(2 * sizeof(char));
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static int	ft_len(int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sim;

	sim = 0;
	len = 0;
	if (n == -2147483648)
		return (ft_int_min());
	if (n < 0)
		sim++;
	if (n == 0)
		return (ft_zero());
	len = ft_len(n);
	str = malloc((len + sim + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (sim)
	{
		str[0] = '-';
		n = n * -1;
	}
	str = ft_char(str, n, (len - 1 + sim));
	str[len + sim] = '\0';
	return (str);
}
// int main(void)
// {
// 	char *s;
// 	s = ft_itoa(-2147483647);
// 	printf("%s",s);
// 	//printf("%s",s);
// }
