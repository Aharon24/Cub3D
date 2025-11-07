/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:49:46 by ahapetro          #+#    #+#             */
/*   Updated: 2025/06/05 17:59:19 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str_n;
	static char	str[BUFFER_SIZE + 1];
	ssize_t		len_red;

	if (fd == -42)
		return (gnl_cline(&str_n));
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!str_n)
		str_n = ft_strdup("");
	len_red = read(fd, str, BUFFER_SIZE);
	while (len_red > 0)
	{
		str[len_red] = '\0';
		str_n = ft_strjoin(str_n, str);
		if (ft_chek_str(str_n, '\n'))
			break ;
		len_red = read(fd, str, BUFFER_SIZE);
	}
	if (len_red == -1 || (len_red == 0 && (!str_n || str_n[0] == '\0')))
		return (ft_len_red(&str_n));
	return (ft_return_n(&str_n));
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		++i;
	}
	sub[len] = '\0';
	return (sub);
}

char	*ft_return_n(char **str_n)
{
	int		i;
	char	*new;
	char	*new_str_n;

	i = 0;
	while ((*str_n)[i] != '\n' && (*str_n)[i])
		i++;
	if ((*str_n)[i] == '\n')
		new = ft_substr(*str_n, 0, i + 1);
	else
		new = ft_strdup(*str_n);
	if ((*str_n)[0] == '\n')
		new_str_n = NULL;
	else if ((*str_n)[i] == '\n')
		new_str_n = ft_strdup(*str_n + i + 1);
	else
		new_str_n = NULL;
	free(*str_n);
	*str_n = new_str_n;
	return (new);
}

char	*gnl_cline(char **str_n)
{
	if (*str_n)
	{
		free(*str_n);
		*str_n = NULL;
	}
	return (NULL);
}

char	*ft_len_red(char **str_n)
{
	if (*str_n)
	{
		free(*str_n);
		*str_n = NULL;
	}
	return (NULL);
}
// int	main(void)
// {
// 	int fd;
// 	fd = 0;
// 	fd = open("Test.txt",O_RDONLY);
// 	printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// //printf("%s\n",get_next_line(fd));
// 	close(fd);
// }