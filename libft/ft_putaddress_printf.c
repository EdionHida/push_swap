/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <ehida@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:13:37 by ehida             #+#    #+#             */
/*   Updated: 2023/05/03 01:37:57 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_ptr(unsigned long long nbr)
{
	int	digit;
	int	res;

	res = 0;
	if (nbr / 16)
		res += ft_print_ptr(nbr / 16);
	digit = nbr % 16;
	if (digit < 10)
		res += ft_putnbr_printf(digit);
	else
		res += ft_putchar_printf((digit - 10) + 'a');
	return (res);
}

int	ft_putaddress_printf(unsigned long long ptr)
{
	int	res;

	res = write(1, "0x", 2);
	res += ft_print_ptr(ptr);
	return (res);
}
