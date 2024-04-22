/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <ehida@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:13:01 by ehida             #+#    #+#             */
/*   Updated: 2023/05/03 01:38:29 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_printf(unsigned int nbr, char c)
{
	int	digit;
	int	res;

	res = 0;
	if (nbr / 16)
		res += ft_puthex_printf((nbr / 16), c);
	digit = nbr % 16;
	if (digit < 10)
		res += ft_putnbr_printf(digit);
	else
	{
		if (c == 'x')
			res += ft_putchar_printf((digit - 10) + 'a');
		else if (c == 'X')
			res += ft_putchar_printf((digit - 10) + 'A');
	}
	return (res);
}
