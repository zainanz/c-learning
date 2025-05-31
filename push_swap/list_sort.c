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
#include <stdio.h>
#include <unistd.h>

void	three_sort(t_list *stack)
{
	t_node	*highest_node;
	t_node	*curr;

	curr = stack->head;
	highest_node = stack->head;
	while (curr)
	{
		if (highest_node->value < curr->value)
			highest_node = curr;
		curr = curr->next;
	}
	if (stack->head == highest_node)
		shift_up(stack);
	else if (stack->head->next == highest_node)
		shift_down(stack);
	if (stack->head->value > stack->head->next->value)
		swap(stack);
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

void	send_top(t_list *stack_a, t_node *node)
{
	int 	i;

	i = 0;
	if (node->index > stack_a->size / 2)
	{
		while (i < stack_a->size - node->index)
		{
			shift_down(stack_a);
			i++;
		}
	}
	else
	{
		while (i < node->index)
		{
			shift_up(stack_a);
			i++;
		}
	}
}

void perform_sort(t_list *stack_a, t_list *stack_b)
{
	t_node	*curr;
	t_node	*node;

	node = NULL;
	curr = stack_b->head;
	while (curr)
	{
		t_node *temp = curr;
		node = find_closest_lowest(stack_a, curr);
		send_top(stack_a, node);
		curr = curr->next;
		push_to_from(stack_a, stack_b);	
	}
}
