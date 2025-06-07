/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:16:46 by zali              #+#    #+#             */
/*   Updated: 2025/06/03 12:33:27 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_stack_sorted(t_stacks *stacks)
{
	t_node	*curr;
	int		prev_val;

	curr = stacks->stack_b->tail;
	if (curr)
	{
		prev_val = curr->value;
		curr = curr->prev;
		while (curr)
		{
			if (prev_val > curr->value)
				return (0);
			prev_val = curr->value;
			curr = curr->prev;
		}
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;

	if (argc == 1)
		return (0);
	stacks = init_stacks();
	stacks_init_string_split(argc, argv, stacks);
	if (is_stack_sorted(stacks))
		return (clean_up_stacks(stacks), 0);
	else
		init_sort_stacks(stacks);
	three_sort(stacks->stack_a);
	perform_sort(stacks->stack_a, stacks->stack_b);
	clean_up_stacks(init_stacks());
	return (0);
}
