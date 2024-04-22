/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:45:16 by ehida             #+#    #+#             */
/*   Updated: 2023/04/04 05:55:51 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	ret;

	ret = ft_strlen(src);
	if (dstsize && dest && src)
	{
		while (*src != '\0' && dstsize > 1)
		{
			*dest = *src;
			src++;
			dest++;
			dstsize--;
		}
		*dest = 0;
	}
	return (ret);
}
