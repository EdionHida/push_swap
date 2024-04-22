/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:38:32 by ehida             #+#    #+#             */
/*   Updated: 2023/01/08 12:41:16 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (del && lst)
	{
		if ((*lst)->next)
			ft_lstclear(&((*lst)->next), del);
		del((*lst)->content);
		free(*lst);
		*lst = 0;
	}
}
