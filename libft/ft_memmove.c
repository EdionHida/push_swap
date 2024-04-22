/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:03:58 by ehida             #+#    #+#             */
/*   Updated: 2022/11/08 15:04:00 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (0);
	if (src < dest)
	{
		src += n;
		dest += n;
		while (n > 0)
		{
			dest--;
			src--;
			*(char *)dest = *(char *)src;
			n--;
		}
	}
	else
		return (ft_memcpy(dest, src, n));
	return (dest);
}
