/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:37:46 by zali              #+#    #+#             */
/*   Updated: 2025/05/26 20:57:24 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	swap(t_list	*lst)
{
	t_node	*temp;

	if (lst->size <= 1 || !lst)
		return ;
	temp = lst->head;
	lst->head = lst->head->next;
	temp->next = lst->head->next;
	lst->head->next = temp;
	lst->head->prev = NULL;
	temp->prev = lst->head;
}

void	push_to_from(t_list *to, t_list *from)
{
	t_node	*from_next;

	if (from->size == 0 || !to || !from)
		return ;
	from_next = from->head->next;
	from->head->next = to->head;
	to->head->prev = from->head;
	to->head = from->head;
	from->head = from_next;
	if (from->head)
		from->head->prev = NULL;
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
	lst->tail = lst->tail->prev;
	lst->head = lst->tail->next;
	lst->head->prev = NULL;
	lst->tail->next = NULL;
}
