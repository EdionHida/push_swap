/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <ehida@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:40:04 by ehida             #+#    #+#             */
/*   Updated: 2023/06/12 12:11:57 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_find_pos(t_node **stack)
{
	t_node	*curr;
	int		i;

	curr = *stack;
	i = 1;
	while (curr != NULL)
	{
		if (curr->index == 1 || curr->index == 2)
		{
			(*stack)->pos = i;
			return ;
		}
		i++;
		curr = curr->next;
	}
}

void	sort_four(t_node **stack)
{
	t_node	*curr;
	int		i;

	curr = *stack;
	i = (*stack)->size - (*stack)->pos;
	if (i == 2)
	{
		while (i++ != 3)
			rotate(stack, 0);
	}
	else if (i == 0 || i == 1)
	{
		while (i-- != -1)
			rev_rotate(stack, 0);
	}
}

int	is_sorted(t_node **stack)
{
	t_node	*curr;

	curr = *stack;
	while (curr->next != NULL)
	{
		if (curr->index > curr->next->index)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	radix_sort(t_node **stack_a, t_node **stack_b, int stack_size)
{
	static int	byte;

	while (stack_size > 0)
	{
		if ((((*stack_a)->index >> byte) & 1) == 1)
			rotate(stack_a, 0);
		else
			push(stack_a, stack_b, 1);
		stack_size--;
	}
	byte++;
}

void	push_back(t_node **stack_b, t_node **stack_a)
{
	int	count;

	ft_get_size(stack_b);
	count = (*stack_b)->size;
	while (count > 0)
	{
		push(stack_b, stack_a, 0);
		count--;
	}
}
