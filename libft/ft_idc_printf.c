/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idc_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <ehida@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:08:38 by ehida             #+#    #+#             */
/*   Updated: 2023/05/03 01:40:00 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_idc_printf(int n, char c)
{
	int	res;

	if (c == 'i' || c == 'd')
		res = ft_putnbr_printf(n);
	else
		res = write(1, &n, 1);
	return (res);
}
