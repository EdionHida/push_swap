/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:52:36 by ehida             #+#    #+#             */
/*   Updated: 2022/11/10 00:52:36 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	find_str(const char *haystack, const char *needle, size_t len)
{
	while (*needle == *haystack && *needle != 0 && len > 0)
	{
		len--;
		needle++;
		haystack++;
	}
	if (*needle == 0)
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == 0)
		return ((char *)haystack);
	while (len > 0 && *haystack != 0)
	{
		if (find_str(haystack, needle, len))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
