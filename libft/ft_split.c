/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:23:31 by ehida             #+#    #+#             */
/*   Updated: 2022/12/07 12:39:55 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	str_num(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	j = 0;
	ret = (char **)malloc(sizeof(char *) * (str_num(s, c) + 1));
	if (ret == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			i = 0;
			while (*s && *s != c && ++i)
				s++;
			ret[j++] = ft_substr(s - i, 0, i);
		}
		else
			s++;
	}
	ret[j] = 0;
	return (ret);
}
