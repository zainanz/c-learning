/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:12:16 by zali              #+#    #+#             */
/*   Updated: 2025/06/03 12:33:15 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	find_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

t_node	*find_smallest(t_list *lst)
{
	t_node	*smallest;
	t_node	*curr;

	smallest = lst->head;
	curr = lst->head;
	while (curr)
	{
		if (curr->value < smallest->value)
			smallest = curr;
		curr = curr->next;
	}
	return (smallest);
}

t_node	*find_closest_lowest(t_list *stack_a, t_node *node)
{
	t_node	*closest_node;
	t_node	*curr;

	closest_node = NULL;
	curr = stack_a->head;
	while (curr)
	{
		if (!closest_node && curr->value > node->value)
			closest_node = curr;
		if (curr->value > node->value && curr->value < closest_node->value)
			closest_node = curr;
		curr = curr->next;
	}
	if (!closest_node)
		closest_node = find_smallest(stack_a);
	return (closest_node);
}

void	update_index(t_list *stack)
{
	int		index;
	t_node	*curr;

	index = 0;
	curr = stack->head;
	while (curr)
	{
		curr->index = index++;
		curr = curr->next;
	}
}
