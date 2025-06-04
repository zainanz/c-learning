/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:34:42 by zali              #+#    #+#             */
/*   Updated: 2025/06/04 12:35:59 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nodes_same_median(t_node *node_a, t_node *node_b)
{
	t_stacks	*stacks;

	stacks = init_stacks();
	return (((node_b->index > stacks->stack_b->size / 2)
			&& (node_a->index > stacks->stack_a->size / 2))
		|| ((node_b->index <= stacks->stack_b->size / 2)
			&& (node_a->index <= stacks->stack_a->size / 2)));
}

void	calculate_cross_method(t_node *curr, t_node *node)
{
	int	temp;
	int	temp2;

	temp = calc_moves_method_c(curr, node);
	if (temp < curr->moves)
	{
		curr->method = METHOD_C_STACK_A;
		curr->moves = temp;
	}
	temp2 = calc_moves_method_d(curr, node);
	if (temp2 < curr->moves)
	{
		curr->method = METHOD_C_STACK_B;
		curr->moves = temp2;
	}
}

t_node	*calculate_best_moves(t_list *stack_a, t_list *stack_b)
{
	t_node	*node;
	t_node	*cheapest;
	t_node	*curr;

	curr = stack_b->head;
	node = NULL;
	cheapest = NULL;
	while (curr)
	{
		node = find_closest_lowest(stack_a, curr);
		curr->closest = node;
		calc_moves_method_base(curr, node);
		if (!nodes_same_median(curr, node))
			calculate_cross_method(curr, node);
		if (!cheapest)
			cheapest = curr;
		if (cheapest->moves > curr->moves)
			cheapest = curr;
		curr = curr->next;
	}
	return (cheapest);
}
