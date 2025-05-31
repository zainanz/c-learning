/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:10:11 by zali              #+#    #+#             */
/*   Updated: 2025/05/26 20:16:16 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_node	*create_node(int value)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	n->value = value;
	n->next = NULL;
	n->prev = NULL;
	return (n);
}
