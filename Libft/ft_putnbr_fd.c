/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:17:26 by ahapetro          #+#    #+#             */
/*   Updated: 2025/02/06 15:17:45 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putft(int fd, int len, char *s)
{
	int	i;

	i = 0;
	i = len;
	while (i > 0)
	{
		write(fd, &s[i - 1], 1);
		i--;
	}
}

static int	ft_min_zero(int n, int fd)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	a[12];
	int		i;

	i = 0;
	if (n == -2147483648 || n == 0)
	{
		ft_min_zero(n, fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (n != 0)
	{
		a[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	a[i] = '\0';
	ft_putft(fd, i, a);
}
// int main(void)
// {
//     int fd;
//     fd = open("z_int.txt",O_WRONLY | O_APPEND | O_CREAT, 0644);
//     ft_putnbr_fd(-2147483648,fd);
//     close(fd);
// }