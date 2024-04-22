/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <ehida@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:37:28 by ehida             #+#    #+#             */
/*   Updated: 2024/04/07 21:48:48 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_set_min(t_node **stack)
{
	t_node	*curr;

	curr = *stack;
	while (curr != NULL)
	{
		curr->index = -1;
		curr = curr->next;
	}
}

static int	ft_find_min(t_node **stack)
{
	t_node	*curr;
	int		counter;
	long	smallest;

	counter = 0;
	if ((*stack) == NULL)
		return (0);
	while (counter < (*stack)->size)
	{
		curr = *stack;
		smallest = 2147483648;
		while (curr != NULL)
		{
			if (smallest > curr->value && curr->index == -1)
			{
				smallest = curr->value;
			}
			curr = curr->next;
		}
		counter++;
	}
	return (smallest);
}

void	ft_add_index(t_node **stack)
{
	t_node	*curr;
	int		smallest;
	int		i;
	int		counter;

	if ((*stack) == NULL)
		return ;
	ft_set_min(stack);
	i = 1;
	counter = -1;
	//smallest = ft_find_min(stack);
	while (++counter < (*stack)->size)
	{
		curr = *stack;
		smallest = ft_find_min(stack);
		printf("smallest: %i\n", smallest);
		while (curr != NULL)
		{
			if (curr->value == smallest)
			{	
				curr->index = i;
				i++;
			}
			curr = curr->next;
		}
	}
}

void	ft_get_size(t_node **stack)
{
	t_node	*curr;
	int		i;

	i = 0;
	curr = *stack;
	if (curr == NULL)
		return ;
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	(*stack)->size = i;
}

void	ft_deallocate(t_node **stack)
{
	t_node	*curr;
	t_node	*tmp;

	curr = *stack;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	*stack = NULL;
}
