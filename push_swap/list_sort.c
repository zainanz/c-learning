/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:00:43 by zali              #+#    #+#             */
/*   Updated: 2025/06/03 12:33:47 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include <stdio.h>

static int	sort_two(t_list *stack)
{
	if (stack->size == 2)
	{
		if (stack->head->value > stack->tail->value)
			ra(stack, 1);
		return (1);
	}
	return (0);
}

void	three_sort(t_list *stack)
{
	t_node	*highest_node;
	t_node	*curr;

	curr = stack->head;
	highest_node = stack->head;
	if (stack->size == 1)
		return ;
	if (sort_two(stack))
		return ;
	while (curr)
	{
		if (highest_node->value < curr->value)
			highest_node = curr;
		curr = curr->next;
	}
	if (stack->head == highest_node)
		ra(stack, 1);
	else if (stack->head->next == highest_node)
		rra(stack, 1);
	if (stack->head->value > stack->head->next->value)
		sa(stack, 1);
}

void	perform_sort(t_list *stack_a, t_list *stack_b)
{
	t_node	*cheapest_node;
	t_node	*smallest;

	cheapest_node = NULL;
	smallest = NULL;
	while (stack_b->size)
	{
		update_index(stack_a);
		update_index(stack_b);
		cheapest_node = set_moves_and_find_cheapest(stack_a, stack_b);
		top_selected_nodes(stack_a, stack_b, cheapest_node);
		pa(stack_a, stack_b);
	}
	update_index(stack_a);
	smallest = find_smallest(stack_a);
	send_top(stack_a, smallest, TYPE_STACK_A);
}
