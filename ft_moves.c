/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <ehida@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 00:36:38 by ehida             #+#    #+#             */
/*   Updated: 2023/06/09 04:28:24 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	swap(t_node **stack, int click)
{
	t_node	*curr;

	if ((*stack) == NULL)
		return ;
	ft_get_size(stack);
	if ((*stack)->size <= 1)
		return ;
	curr = *stack;
	*stack = (*stack)->next;
	curr->next = (*stack)->next;
	(*stack)->next = curr;
	if (click == 0)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	rotate(t_node **stack, int click)
{
	t_node	*head;
	t_node	*end;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	end = *stack;
	head = *stack;
	(*stack) = (*stack)->next;
	while (end->next != NULL)
		end = end->next;
	head->next = end->next;
	end->next = head;
	if (click == 0)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	rev_rotate(t_node **stack, int click)
{
	t_node	*head;
	t_node	*end;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	end = *stack;
	head = *stack;
	while ((*stack)->next != NULL)
		(*stack) = (*stack)->next;
	while (end->next->next != NULL)
		end = end->next;
	end->next = (*stack)->next;
	(*stack)->next = head;
	if (click == 0)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}

void	push(t_node **source, t_node **target, int click)
{
	t_node	*top_source;
	t_node	*copy;

	if ((*source) == NULL)
		return ;
	top_source = (*source)->next;
	copy = (*source);
	copy->next = (*target);
	(*target) = copy;
	(*source) = top_source;
	if (click == 0)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}
