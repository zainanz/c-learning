/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:24:10 by zali              #+#    #+#             */
/*   Updated: 2025/06/04 12:27:00 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_method_c(t_list *stack_a, t_list *stack_b, t_node *cheapest)
{
	if (cheapest->closest->index > stack_a->size / 2)
		rrr(stack_a, stack_b, stack_a->size - cheapest->closest->index);
	else
		rr(stack_a, stack_b, cheapest->closest->index);
	update_index(stack_b);
	if (cheapest->index > stack_b->size / 2)
		rrb(stack_b, stack_b->size - cheapest->index);
	else
		rb(stack_b, cheapest->index);
}

void	sort_method_d(t_list *stack_a, t_list *stack_b, t_node *cheapest)
{
	if (cheapest->index > stack_b->size / 2)
		rrr(stack_a, stack_b, stack_b->size - cheapest->index);
	else
		rr(stack_a, stack_b, cheapest->index);
	update_index(stack_a);
	if (cheapest->closest->index > stack_a->size / 2)
		rra(stack_a, stack_a->size - cheapest->closest->index);
	else
		ra(stack_a, cheapest->closest->index);
}

void	sort_cheapest_node(t_list *stack_a, t_list *stack_b, t_node *cheapest)
{
	if (cheapest->method == 1 || cheapest->method == 2)
		top_selected_nodes(stack_a, stack_b, cheapest);
	else if (cheapest->method == 3)
		sort_method_c(stack_a, stack_b, cheapest);
	else if (cheapest->method == 4)
		sort_method_d(stack_a, stack_b, cheapest);
}
