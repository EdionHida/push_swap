/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:42:25 by ehida             #+#    #+#             */
/*   Updated: 2022/12/22 20:42:29 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (i + 1);
	if (nbr < 0)
		i++;
	while (nbr)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			count;
	char		*ret;
	const char	*digits;

	digits = "0123456789";
	count = ft_count(n);
	ret = (char *)malloc((count + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ret[count] = '\0';
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
		ret[0] = '-';
	count--;
	while (n)
	{
		if (n > 0)
			ret[count--] = digits[n % 10];
		else
			ret[count--] = digits[n % 10 * -1];
		n = n / 10;
	}
	return (ret);
}
