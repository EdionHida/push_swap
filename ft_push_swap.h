/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehida <ehida@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:24:21 by ehida             #+#    #+#             */
/*   Updated: 2024/04/07 21:20:27 by ehida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	int				size;
	int				pos;
	struct s_node	*next;
}	t_node;

void	ft_parse(t_node **list, int argc, char **argv);
void	ft_exit(void);
void	ft_deallocate(t_node **stack);
void	ft_get_size(t_node **stack);
void	ft_add_index(t_node **stack);

void	swap(t_node **stack, int click);
void	rotate(t_node **stack, int click);
void	rev_rotate(t_node **stack, int click);
void	push(t_node **source, t_node **target, int click);

int		is_sorted(t_node **stack);
void	ft_sort_three(t_node **stack);
void	ft_sort(t_node **stack_a, t_node **stack_b);
void	ft_find_pos(t_node **stack);
void	sort_four(t_node **stack);
void	radix_sort(t_node **stack_a, t_node **stack_b, int stack_size);
void	push_back(t_node **stack_b, t_node **stack_a);

#endif