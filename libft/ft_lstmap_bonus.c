/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <ehida@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:24:48 by ehida             #+#    #+#             */
/*   Updated: 2023/06/05 03:51:43 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *))
{
	t_list	*root;
	t_list	*new_node;

	if (lst)
	{
		root = ft_lstnew(f(lst->content));
		if (root == 0)
			return (0);
		lst = lst->next;
	}
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == 0)
		{
			ft_lstclear(&root, d);
			return (0);
		}
		ft_lstadd_back(&root, new_node);
		lst = lst->next;
	}
	return (root);
}
