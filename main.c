/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <ehida@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:04:28 by ehida             #+#    #+#             */
/*   Updated: 2024/04/07 21:22:09 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	ft_parse(&stack_a, argc, argv);
	ft_sort(&stack_a, &stack_b);
	ft_deallocate(&stack_a);
	ft_deallocate(&stack_b);
	return (0);
}
