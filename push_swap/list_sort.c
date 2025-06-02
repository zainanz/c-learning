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

t_node	*set_moves_and_find_cheapest(t_list *stack_a, t_list *stack_b)
{
	t_node	*curr;
	t_node	*cheapest_node;
	t_node	*node;

	curr = stack_b->head;
	cheapest_node = NULL;
	node = NULL;
	while (curr)
	{
		node = find_closest_lowest(stack_a, curr);
		if (node->index > stack_a->size / 2)
			curr->moves = stack_a->size - node->index;
		else
			curr->moves = node->index;
		if (curr->index > stack_b->size / 2)
			curr->moves += stack_b->size - curr->index;
		else
			curr->moves += curr->index;
		if (!cheapest_node)
			cheapest_node = curr;
		if (cheapest_node->moves > curr->moves)
			cheapest_node = curr;
		curr->closest = node;
		curr = curr->next;
	}
	return (cheapest_node);
}

void	double_shift_down(t_list *stack_a, t_list *stack_b, t_node *cheapest_node)
{
	int	a_times;
	int	b_times;

	a_times = stack_a->size - cheapest_node->closest->index; 
	b_times	= stack_b->size - cheapest_node->index;
	if (a_times < b_times)
		rrr(stack_a, stack_b, a_times);
	else
		rrr(stack_a, stack_b, b_times);
}

void	double_shift_up(t_list *stack_a, t_list *stack_b, t_node *cheapest_node)
{
	int	a_times;
	int	b_times;

	a_times = cheapest_node->closest->index; 
	b_times	= cheapest_node->index;
	if (a_times < b_times)
		rr(stack_a, stack_b, a_times);
	else
		rr(stack_a, stack_b, b_times);
}

void stacks_shift(t_list *stack_a, t_list *stack_b, t_node *cheapest_node)
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

void	send_stacks_top(t_list *stack_a, t_list *stack_b, t_node *cheapest_node)
{
	if ((cheapest_node->index > stack_b->size / 2) &&
			(cheapest_node->closest->index > stack_a->size / 2))
		double_shift_down(stack_a, stack_b, cheapest_node);
	else if ((cheapest_node->index <= stack_b->size / 2) &&
			(cheapest_node->closest->index <= stack_a->size))
		double_shift_up(stack_a, stack_b, cheapest_node);
	stacks_shift(stack_a, stack_b, cheapest_node);	
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
		send_stacks_top(stack_a, stack_b, cheapest_node);
		pa(stack_a, stack_b);
	}
	update_index(stack_a);
	smallest = find_smallest(stack_a);
	send_top(stack_a, smallest, TYPE_STACK_A);
}
