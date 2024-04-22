/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unbr_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <ehida@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:12:19 by ehida             #+#    #+#             */
/*   Updated: 2023/05/03 01:37:46 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_unbr_printf(unsigned int nbr)
{
	int	res;

	res = 0;
	if (nbr > 9)
		res += ft_put_unbr_printf(nbr / 10);
	ft_putchar_printf(nbr % 10 + '0');
	res++;
	return (res);
}
