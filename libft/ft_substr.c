/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:27:39 by ehida             #+#    #+#             */
/*   Updated: 2022/11/10 03:27:41 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (ft_strlen(s + start) >= len)
		res = (char *)malloc(len + 1);
	else
		res = (char *)malloc(ft_strlen(s + start) + 1);
	if (res == NULL || s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		*res = 0;
		return (res);
	}
	ft_strlcpy(res, s + start, len + 1);
	return (res);
}
