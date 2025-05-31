/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:49:30 by zali              #+#    #+#             */
/*   Updated: 2025/05/26 20:39:20 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_list	*lst_init(void)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->head = NULL;
	lst->tail = NULL;
	lst->size = 0;
	return (lst);
}

void	push_node(t_list *lst, t_node	*node)
{
	if (!lst || !node)
		return ;
	node->next = lst->head;
	if (lst->head == NULL)
		lst->head = node;
	if (lst->tail == NULL)
		lst->tail = node;
	lst->head->prev = node;
	lst->head = node;
	lst->size++;
}

void	clear_lst(t_list *lst)
{
	if (!lst)
		return ;
	t_node	*next;
	t_node	*cur;

	cur = lst->head;
	next = NULL;
	lst->head = NULL;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
}

void	print_lst(t_list *lst)
{
	t_node	*n;

	n = lst->head;
	while (n)
	{
		printf("%i\n", n->value);
		n = n->next;
	}
}
