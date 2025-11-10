/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:27:04 by ahapetro          #+#    #+#             */
/*   Updated: 2025/02/05 15:27:40 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

// int main(void)
// {
//     int fd;

//     fd = open("z.txt",O_WRONLY | O_APPEND | O_CREAT ,0644);
//     ft_putchar_fd('H',fd);
//     close(fd);
//     return(0);
// }