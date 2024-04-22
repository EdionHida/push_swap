/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <ehida@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 04:31:13 by ehida             #+#    #+#             */
/*   Updated: 2023/07/04 19:38:38 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_act(t_node **stack)
{
	t_node	*curr;
	int		i;

	curr = *stack;
	if ((*stack)->size == 4)
	{
		sort_four(stack);
		return ;
	}
	i = (*stack)->size - (*stack)->pos;
	if (i == 2 || i == 3)
	{
		while (i++ != 4)
			rotate(stack, 0);
	}
	else if (i == 0 || i == 1)
	{
		while (i-- != -1)
			rev_rotate(stack, 0);
	}
}

static void	ft_sort_big(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	byte;

	i = (*stack_a)->size;
	byte = 0;
	while (byte <= 31)
	{
		radix_sort(stack_a, stack_b, i);
		push_back(stack_b, stack_a);
		if (is_sorted(stack_a) == 1)
			break ;
		byte++;
	}
}

static void	ft_sort_five(t_node **stack_a, t_node **stack_b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		ft_get_size(stack_a);
		ft_find_pos(stack_a);
		if ((*stack_a)->pos == 1)
			push(stack_a, stack_b, 1);
		else
		{	
			ft_act(stack_a);
			push(stack_a, stack_b, 1);
		}
		i++;
	}
	ft_get_size(stack_a);
	if (is_sorted(stack_b) == 1)
		swap(stack_b, 1);
	if (is_sorted(stack_a) == 0 && (*stack_a)->size == 3)
		ft_sort_three(stack_a);
	else if (is_sorted(stack_a) == 0 && (*stack_a)->size == 2)
		swap(stack_a, 0);
	push(stack_b, stack_a, 0);
	push(stack_b, stack_a, 0);
}

void	ft_sort_three(t_node **stack)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack)->index;
	middle = (*stack)->next->index;
	bottom = (*stack)->next->next->index;
	if (top > middle && top < bottom)
		swap(stack, 0);
	else if (top < middle && top > bottom)
		rev_rotate(stack, 0);
	else if (top > middle && top > bottom && middle < bottom)
		rotate(stack, 0);
	else if (top > middle && top > bottom)
	{
		rotate(stack, 0);
		swap(stack, 0);
	}
	else
	{
		rev_rotate(stack, 0);
		swap(stack, 0);
	}
}

void	ft_sort(t_node **stack_a, t_node **stack_b)
{
	int	len;

	if (!(*stack_a))
		return ;
	len = (*stack_a)->size;
	if (is_sorted(stack_a) == 1)
		return ;
	if (len == 2)
		swap(stack_a, 0);
	else if (len == 3)
		ft_sort_three(stack_a);
	else if (len <= 5)
		ft_sort_five(stack_a, stack_b);
	else
		ft_sort_big(stack_a, stack_b);
}
