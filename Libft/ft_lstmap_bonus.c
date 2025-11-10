/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:29:28 by ahapetro          #+#    #+#             */
/*   Updated: 2025/02/10 21:29:31 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*info;
	void	*cont;

	new = NULL;
	while (lst)
	{
		cont = f(lst->content);
		if (!cont)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		info = ft_lstnew(cont);
		if (!info)
		{
			del(info->content);
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new, info);
		lst = lst->next;
	}
	return (new);
}
