/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves_methods.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:25:15 by zali              #+#    #+#             */
/*   Updated: 2025/06/04 12:33:13 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_moves_method_base_b(t_node *curr, t_node *closest)
{
	t_stacks	*stacks;
	int			moves;

	moves = 0;
	stacks = init_stacks();
	if (closest->index > stacks->stack_a->size / 2)
		moves = stacks->stack_a->size - closest->index;
	else
		moves = closest->index;
	if (curr->index > stacks->stack_b->size / 2)
		moves += stacks->stack_b->size - curr->index;
	else
		moves += curr->index;
	return (moves);
}

void	calc_moves_method_base(t_node *curr, t_node *closest)
{
	int	m_a;
	int	m_b;
	int	dist_curr;
	int	dist_closest;

	m_a = find_max(curr->index, closest->index);
	if (nodes_same_median(curr, closest))
	{
		dist_curr = curr->index;
		if (curr->index > init_stacks()->stack_b->size / 2)
			dist_curr = init_stacks()->stack_b->size - curr->index;
		dist_closest = closest->index;
		if (closest->index > init_stacks()->stack_a->size / 2)
			dist_closest = init_stacks()->stack_a->size - closest->index;
		m_a = find_max(dist_closest, dist_curr);
	}
	m_b = calc_moves_method_base_b(curr, closest);
	curr->moves = find_min(m_b, m_a);
	if (m_a >= m_b)
		curr->method = METHOD_B;
	if (m_a < m_b)
		curr->method = METHOD_A;
}

int	calc_moves_method_c(t_node *curr, t_node *closest)
{
	t_stacks	*stacks;
	int			moves;
	int			node_b_index;

	stacks = init_stacks();
	if (closest->index > stacks->stack_a->size / 2)
	{
		moves = stacks->stack_a->size - closest->index;
		node_b_index = (moves % stacks->stack_b->size) + curr->index;
		if (node_b_index > stacks->stack_b->size - 1)
			node_b_index -= stacks->stack_b->size;
	}
	else
	{
		moves = closest->index;
		node_b_index = curr->index - (moves % stacks->stack_b->size);
		if (node_b_index < 0)
			node_b_index = stacks->stack_b->size + node_b_index;
	}
	if (node_b_index > stacks->stack_b->size / 2)
		moves += stacks->stack_b->size - node_b_index;
	else
		moves += node_b_index;
	return (moves);
}

int	calc_moves_method_d(t_node *curr, t_node *closest)
{
	t_stacks	*stacks;
	int			moves;
	int			node_a_index;

	stacks = init_stacks();
	if (curr->index > stacks->stack_b->size / 2)
	{
		moves = stacks->stack_b->size - curr->index;
		node_a_index = (moves % stacks->stack_a->size) + closest->index;
		if (node_a_index > stacks->stack_a->size - 1)
			node_a_index -= stacks->stack_a->size;
	}
	else
	{
		moves = curr->index;
		node_a_index = closest->index - (moves % stacks->stack_a->size);
		if (node_a_index < 0)
			node_a_index = stacks->stack_a->size + node_a_index;
	}
	if (node_a_index > stacks->stack_a->size / 2)
		moves += stacks->stack_a->size - node_a_index;
	else
		moves += node_a_index;
	return (moves);
}
