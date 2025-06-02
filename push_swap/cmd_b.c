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

void	rb(t_list *lst, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		shift_up(lst);
		write(1, "rb\n", 3);
		i++;
	}
}

void	rrb(t_list *lst, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		shift_down(lst);
		write(1, "rrb\n", 4);
		i++;
	}
}

void	rrr(t_list *stack_a, t_list *stack_b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		shift_down(stack_a);
		shift_down(stack_b);
		write(1, "rrr\n", 4);
		i++;
	}
}

void	rr(t_list *stack_a, t_list *stack_b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		shift_up(stack_a);
		shift_up(stack_b);
		write(1, "rr\n", 3);
		i++;
	}
}
