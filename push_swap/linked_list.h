/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:49:49 by zali              #+#    #+#             */
/*   Updated: 2025/05/31 08:51:09 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H

# define LINKED_LIST_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct node
{
	int			value;
	int			index;
	struct node	*next;
	struct node	*prev;
}	t_node;

typedef struct s_linked_list
{
	struct node	*head;
	struct node	*tail;
	int			size;
}	t_list;

//Helper
int		ft_atoi(const char *str);
int		valid_num(char *str);
int		display_error(void);

// Nodes
t_node	*create_node(int value);

// Linked List
t_list	*lst_init(void);
void	clear_lst(t_list *lst);
void	push_node(t_list *lst, t_node	*node);
void	print_lst(t_list *lst);


// Linked List Utils - PUSH SWAP
void	swap(t_list	*lst);
void	push_to_from(t_list *to, t_list *from);
void	shift_up(t_list *lst);
void	shift_down(t_list *lst);

// Sort
void	three_sort(t_list *stack);
void 	perform_sort(t_list *stack_a, t_list *stack_b);

#endif
