/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <ehida@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:07:53 by ehida             #+#    #+#             */
/*   Updated: 2023/05/03 01:23:15 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

int	ft_strchr_gnl(const char *s, int c)
{
	int	len;
	int	i;

	len = ft_strlen_gnl(s) + 1;
	i = 0;
	while (i < len)
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	char	*ret;
	size_t	total_len;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (0);
	total_len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	ret = (char *)malloc(total_len + 1);
	if (ret == NULL)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}
