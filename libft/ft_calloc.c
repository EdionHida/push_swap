/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 02:55:13 by ehida             #+#    #+#             */
/*   Updated: 2023/01/08 14:22:38 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	malloc_size;

	malloc_size = count * size;
	if (size > 0 && malloc_size / size != count)
		return (NULL);
	ret = malloc(count * size);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, count * size);
	return (ret);
}
