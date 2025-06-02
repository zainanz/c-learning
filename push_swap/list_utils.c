/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:37:46 by zali              #+#    #+#             */
/*   Updated: 2025/06/01 15:09:13 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include <stdio.h>

void	swap(t_list *lst)
{
	t_node	*temp;

	if (lst->size <= 1 || !lst)
		return ;
	temp = lst->head;
	lst->head = lst->head->next;
	temp->next = lst->head->next;
	temp->prev = lst->head;
	if (lst->head->next)
		lst->head->next->prev = temp;
	lst->head->next = temp;
	lst->head->prev = NULL;
	temp->prev = lst->head;
	if (lst->size == 2)
		lst->tail = lst->head->next;
}

void	push_to_from(t_list *to, t_list *from)
{
	t_node	*from_next;

	if (from->size == 0 || !to || !from)
		return ;
	if (from->size == 1)
		from->tail = NULL;
	from_next = from->head->next;
	from->head->next = to->head;
	if (to->head)
		to->head->prev = from->head;
	to->head = from->head;
	from->head = from_next;
	if (from->head)
		from->head->prev = NULL;
	to->head->prev = NULL;
	if (!to->tail)
		to->tail = to->head;
	from->size--;
	to->size++;
}

void	shift_up(t_list *lst)
{
	if (!lst || lst->size <= 1)
		return ;
	lst->tail->next = lst->head;
	lst->head->prev = lst->tail;
	lst->head = lst->head->next;
	lst->tail = lst->head->prev;
	lst->head->prev = NULL;
	lst->tail->next = NULL;
}

void	shift_down(t_list *lst)
{
	if (!lst || lst->size <= 1)
		return ;
	lst->head->prev = lst->tail;
	lst->tail->next = lst->head;
	lst->head = lst->tail;
	lst->tail = lst->tail->prev;
	lst->head->prev = NULL;
	lst->tail->next = NULL;
}

void	send_top(t_list *stack, t_node *node, int type)
{
	void	(*rr)(t_list *, int);
	void	(*r)(t_list *, int);

	rr = rrb;
	r = rb;
	if (type == TYPE_STACK_A)
	{
		rr = rra;
		r = ra;
	}
	if (node->index > stack->size / 2)
		rr(stack, stack->size - node->index);
	else
		r(stack, node->index);
}
