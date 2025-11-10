/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:52:49 by ahapetro          #+#    #+#             */
/*   Updated: 2025/02/05 15:53:28 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
}
// int main(void)
// {
//    int fd;

//     fd =  open("zz.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
//     ft_putstr_fd("HEllO WORD 42\n",fd);

//     close(fd);
// }