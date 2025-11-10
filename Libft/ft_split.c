/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:03:59 by ahapetro          #+#    #+#             */
/*   Updated: 2025/02/04 14:04:12 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_len(char const *s1, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s1[i] != '\0')
	{
		while (s1[i] == c && s1[i])
			i++;
		if (s1[i] != '\0')
			count++;
		while (s1[i] != c && s1[i])
			i++;
	}
	return (count);
}

static char	*ft_strndup(const char *s1, int n)
{
	char	*s;
	int		i;

	i = 0;
	s = malloc((n + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (s1[i] != '\0' && i < n)
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static void	ft_free_split(char **arr, int j)
{
	while (j >= 0)
		free(arr[j--]);
	free(arr);
}

static int	ft_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		i;
	char	**new;

	if (!s)
		return (NULL);
	j = 0;
	i = 0;
	new = (char **)malloc(((ft_word_len(s, c)) + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	while (s[i] && j < (ft_word_len(s, c)))
	{
		while (s[i] == c && s[i])
			i++;
		new[j] = ft_strndup((char *)(s + i), ft_len((char *)(s + i), c));
		if (!new[j])
			ft_free_split(new, j - 1);
		j++;
		while (s[i] != c && s[i])
			i++;
	}
	new[j] = NULL;
	return (new);
}
// int main(void)
// {
// 	char a[] = "hello";
// 	char **s;
// 	int i = 0;
// 	 s = ft_split(a,' ');
// 	while(i < 2)
// 	{
// 		printf("%s\n",s[i]);
// 		i++;
// 	}
// }