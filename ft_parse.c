/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <ehida@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:17:09 by ehida             #+#    #+#             */
/*   Updated: 2024/04/07 21:24:14 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_check_dup(t_node **stack)
{
	int		click;
	t_node	*curr;
	t_node	*copy;

	curr = *stack;
	while (curr != NULL)
	{
		click = 0;
		copy = curr;
		while (copy != NULL)
		{
			if (copy->value == curr->value)
			{
				click++;
				if (click > 1)
					ft_exit();
			}
			copy = copy->next;
		}
		curr = curr->next;
	}
}

static void	ft_add_to_stack(t_node **stack, int value)
{
	t_node	*new_node;
	t_node	*curr;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		ft_exit();
	new_node->value = value;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	curr = *stack;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new_node;
}

static void	ft_fill_stack(t_node **stack, char **argv, int click)
{
	while (argv[click])
	{
		ft_add_to_stack(stack, ft_atoi(argv[click]));
		click++;
	}
}

static void	ft_check_2d(char **list, int i)
{
	int	j;

	while (list[i])
	{
		if (ft_atoi(list[i]) > INT_MAX || ft_atoi(list[i]) < INT_MIN)
			ft_exit();
		j = 0;
		if ((list[i][j] == '-' || list[i][j] == '+'))
			j++;
		if (list[i][j] == '\0')
			ft_exit();
		while (list[i][j] != '\0')
		{
			if ((list[i][j] >= 48 && list[i][j] <= 57))
				j++;
			else
				ft_exit();
		}
		i++;
	}
}

void	ft_parse(t_node **stack, int argc, char **argv)
{
	char	**av;

	if (argc == 2)
	{
		av = ft_split(argv[1], ' ');
		if (av == NULL)
			ft_exit();
		ft_check_2d(av, 0);
		ft_fill_stack(stack, av, 0);
		free_2d((void **)av);
	}
	else
	{
		ft_check_2d(argv, 1);
		ft_fill_stack(stack, argv, 1);
	}
	ft_get_size(stack);
	ft_check_dup(stack);
	ft_add_index(stack);
}
