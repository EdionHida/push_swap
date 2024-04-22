/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <ehida@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:21:51 by ehida             #+#    #+#             */
/*   Updated: 2023/05/03 01:35:32 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_helper(char c, va_list args)
{
	int	res;

	res = 0;
	if (c == 'i' || c == 'd' || c == 'c')
		res += ft_idc_printf(va_arg(args, int), c);
	else if (c == 's')
		res += ft_putstr_printf(va_arg(args, char *));
	else if (c == 'u')
		res += ft_put_unbr_printf(va_arg(args, unsigned int));
	else if (c == '%')
		res += write(1, &c, 1);
	else if (c == 'x' || c == 'X')
		res += ft_puthex_printf(va_arg(args, unsigned int), c);
	else if (c == 'p')
		res += ft_putaddress_printf(va_arg(args, unsigned long long));
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		res;

	va_start(args, str);
	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] != '\0')
				res += ft_printf_helper(str[i], args);
			else
				break ;
		}
		else
			res += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (res);
}
