/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <ehida@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:42:42 by ehida             #+#    #+#             */
/*   Updated: 2023/06/01 21:04:24 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_whitespace(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

long long	ft_atoi(const char *str)
{
	int			i;
	int			min;
	long long	ret;

	i = is_whitespace(str);
	min = 1;
	if (str[i] == '-')
	{
		min = min * -1;
		i++;
	}
	else if (str[i] == '+')
	{
		min = min * 1;
		i++;
	}
	ret = 0;
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{	
		ret = (ret * 10) + (str[i] - 48);
		i++;
	}
	ret = ret * min;
	return (ret);
}
