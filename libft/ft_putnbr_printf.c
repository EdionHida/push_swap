/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <ehida@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:10:21 by ehida             #+#    #+#             */
/*   Updated: 2023/05/03 01:38:37 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_printf(int nbr)
{
	int	res;

	res = 0;
	if (nbr == -2147483648)
	{
		return (ft_printf("-2147483648"));
	}
	else if (nbr < 0)
	{
		res = ft_putchar_printf('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		res += ft_putnbr_printf(nbr / 10);
	ft_putchar_printf(nbr % 10 + '0');
	res++;
	return (res);
}
