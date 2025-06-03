/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_and_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:49:30 by zali              #+#    #+#             */
/*   Updated: 2025/06/03 12:21:18 by zali             ###   ########.fr       */
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

void	push_node(t_list *lst, t_node *node)
{
	if (!lst || !node)
	{
		handle_malloc_error(NULL);
		return ;
	}
	node->next = lst->head;
	if (!lst->tail)
		lst->tail = node;
	if (lst->head)
		lst->head->prev = node;
	lst->head = node;
	lst->size++;
}

void	clear_lst(t_list *lst)
{
	t_node	*next;
	t_node	*cur;

	if (!lst)
		return ;
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
	printf("\n=HEAD: %p - TAIL: (&%p) - SIZE: (%i)=\n", lst->head, lst->tail,
		lst->size);
	while (n)
	{
		printf("%p | PREV: (%p) - VAL: %i\
			- INDEX: (%i) MOVES: (%i) Closest: &(%p) - NEXT: &(%p)\n", n,
			n->prev, n->value, n->index, n->moves, n->closest, n->next);
		n = n->next;
	}
}

t_node	*create_node(int value)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->next = NULL;
	n->prev = NULL;
	n->index = 0;
	n->moves = 0;
	n->closest = NULL;
	return (n);
}
