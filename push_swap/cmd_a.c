/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 08:34:33 by zali              #+#    #+#             */
/*   Updated: 2025/05/31 08:46:33 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	sa(t_list *lst, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		swap(lst);
		write(1, "sa\n", 3);
		i++;
	}
}

void	ra(t_list *lst, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		shift_up(lst);
		write(1, "ra\n", 3);
		i++;
	}
}

void	rra(t_list *lst, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		shift_down(lst);
		write(1, "rra\n", 4);
		i++;
	}
}

void	pa(t_list *stack_a, t_list *stack_b)
{
	write(1, "pa\n", 3);
	push_to_from(stack_a, stack_b);
}
