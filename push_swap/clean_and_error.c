/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:33:10 by zali              #+#    #+#             */
/*   Updated: 2025/06/03 12:21:10 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_up_stacks(t_stacks *stacks)
{
	clear_lst(stacks->stack_a);
	clear_lst(stacks->stack_b);
	free(stacks->stack_a);
	free(stacks->stack_b);
}

void	handle_malloc_error(t_stacks *stacks)
{
	if (!stacks)
		stacks = init_stacks();
	clean_up_stacks(stacks);
	exit(EXIT_FAILURE);
}

void	handle_str_error(t_stacks *stacks)
{
	if (!stacks)
		stacks = init_stacks();
	clean_up_stacks(stacks);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
