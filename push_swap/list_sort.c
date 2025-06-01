/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:00:43 by zali              #+#    #+#             */
/*   Updated: 2025/05/31 08:50:14 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	three_sort(t_list *stack)
{
	t_node	*highest_node;
	t_node	*curr;

	curr = stack->head;
	highest_node = stack->head;
	if (stack->size == 1)
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

t_node	*find_closest_lowest(t_list *stack_a, t_node *node)
{
	int		node_index;
	t_node	*closest_node;
	t_node	*curr;

	node_index = 0;
	closest_node = NULL;
	curr = stack_a->head;
	while (curr)
	{
		if (!closest_node && curr->value > node->value)
			closest_node = curr;
		if (curr->value > node->value && curr->value < closest_node->value)
			closest_node = curr;
		curr->index = node_index++;
		curr = curr->next;
	}
	return (closest_node);
}

t_node	*find_smallest(t_list *lst)
{
	t_node	*smallest;
	t_node	*curr;
	int		index;

	smallest = lst->head;
	curr = lst->head;
	index = 0;
	while (curr)
	{
		if (curr->value < smallest->value)
			smallest = curr;
		curr->index = index++;
		curr = curr->next;
	}
	return (smallest);
}

void	perform_sort(t_list *stack_a, t_list *stack_b)
{
	t_node	*curr;
	t_node	*node;
	t_node	*temp;

	node = NULL;
	curr = stack_b->head;
	while (curr)
	{
		temp = curr;
		node = find_closest_lowest(stack_a, curr);
		if (node)
			send_top(stack_a, node);
		curr = curr->next;
		pa(stack_a, stack_b);
	}
}
