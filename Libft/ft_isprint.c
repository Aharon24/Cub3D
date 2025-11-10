/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:15:15 by ahapetro          #+#    #+#             */
/*   Updated: 2025/01/26 12:57:45 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/*
int main(void)
{
	char a = ' ';
	char b = '~';
	printf("My space : %d\n",ft_isprint(a));
	printf("My ~: %d\n",ft_isprint(b));
	printf("My 180 : %d\n",ft_isprint(180));
	printf("My 12: %d\n",ft_isprint(12));

	printf("Or spase  : %d\n",isprint(a));
	printf("Or ~ : %d\n",isprint(b));
	printf("Or 180 : %d\n",isprint(180));
	printf("Or 12 : %d\n",isprint(12));
}*/
