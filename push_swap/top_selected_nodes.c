/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_selected_nodes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:09:31 by zali              #+#    #+#             */
/*   Updated: 2025/06/04 12:27:13 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	double_shift_down(t_list *stack_a, t_list *stack_b,
		t_node *cheapest_node)
{
	int	a_times;
	int	b_times;

	a_times = stack_a->size - cheapest_node->closest->index;
	b_times = stack_b->size - cheapest_node->index;
	if (a_times < b_times)
		rrr(stack_a, stack_b, a_times);
	else
		rrr(stack_a, stack_b, b_times);
}

static void	double_shift_up(t_list *stack_a, t_list *stack_b,
		t_node *cheapest_node)
{
	int	a_times;
	int	b_times;

	a_times = cheapest_node->closest->index;
	b_times = cheapest_node->index;
	if (a_times < b_times)
		rr(stack_a, stack_b, a_times);
	else
		rr(stack_a, stack_b, b_times);
}

static void	stacks_shift(t_list *stack_a, t_list *stack_b,
		t_node *cheapest_node)
{
	update_index(stack_a);
	update_index(stack_b);
	if (cheapest_node->index > stack_b->size / 2)
		rrb(stack_b, stack_b->size - cheapest_node->index);
	else
		rb(stack_b, cheapest_node->index);
	if (cheapest_node->closest->index > stack_a->size / 2)
		rra(stack_a, stack_a->size - cheapest_node->closest->index);
	else
		ra(stack_a, cheapest_node->closest->index);
}

void	top_selected_nodes(t_list *stack_a, t_list *stack_b,
		t_node *cheapest_node)
{
	if ((cheapest_node->index > stack_b->size / 2)
		&& (cheapest_node->closest->index > stack_a->size / 2))
		double_shift_down(stack_a, stack_b, cheapest_node);
	else if ((cheapest_node->index <= stack_b->size / 2)
		&& (cheapest_node->closest->index <= stack_a->size / 2))
		double_shift_up(stack_a, stack_b, cheapest_node);
	stacks_shift(stack_a, stack_b, cheapest_node);
}
