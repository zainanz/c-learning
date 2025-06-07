/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:49:49 by zali              #+#    #+#             */
/*   Updated: 2025/06/03 12:33:39 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

enum
{
	TYPE_STACK_A,
	TYPE_STACK_B
};

enum
{
	METHOD_A = 1,
	METHOD_B,
	METHOD_C_STACK_A,
	METHOD_C_STACK_B
};

typedef struct node
{
	int						value;
	int						index;
	int						moves;
	int						method;
	struct node				*closest;
	struct node				*next;
	struct node				*prev;
}							t_node;

typedef struct s_linked_list
{
	struct node				*head;
	struct node				*tail;
	int						size;
}							t_list;

typedef struct s_stacks
{
	struct s_linked_list	*stack_a;
	struct s_linked_list	*stack_b;
}							t_stacks;

// Helper
long						ft_atol(const char *str);
int							valid_num(char *str);

// Error Handling and Cleanup
void						handle_str_error(t_stacks *stacks);
void						handle_malloc_error(t_stacks *stacks);
void						clean_up_stacks(t_stacks *stacks);

// Nodes
t_node						*create_node(int value);

// Linked List
t_list						*lst_init(void);
void						clear_lst(t_list *lst);
void						push_node(t_list *lst, t_node *node);
void						print_lst(t_list *lst);

// Linked List Utils - PUSH SWAP
void						swap(t_list *lst);
void						push_to_from(t_list *to, t_list *from);
void						shift_up(t_list *lst);
void						shift_down(t_list *lst);
void						send_top(t_list *stack_a, t_node *node, int type);
void						update_index(t_list *stack);

// CMD
void						ra(t_list *lst, int n);
void						rra(t_list *lst, int n);
void						sa(t_list *lst, int n);
void						pa(t_list *stack_a, t_list *stack_b);
void						rb(t_list *lst, int n);
void						rrb(t_list *lst, int n);
void						rrr(t_list *stack_a, t_list *stack_b, int n);
void						rr(t_list *stack_a, t_list *stack_b, int n);

// Sort
void						three_sort(t_list *stack);
void						perform_sort(t_list *stack_a, t_list *stack_b);
void						sort_cheapest_node(t_list *stack_a, t_list *stack_b,
								t_node *cheapest);
// Sort Methods
void						top_selected_nodes(t_list *stack_a, t_list *stack_b,
								t_node *cheapest_node);
void						sort_method_d(t_list *stack_a, t_list *stack_b,
								t_node *cheapest);
void						sort_method_c(t_list *stack_a, t_list *stack_b,
								t_node *cheapest);

// Calculation
t_node						*calculate_best_moves(t_list *stack_a,
								t_list *stack_b);
void						calculate_cross_method(t_node *curr, t_node *node);
int							nodes_same_median(t_node *node_a, t_node *node_b);

// Calc methods
void						calc_moves_method_base(t_node *curr,
								t_node *closest);
int							calc_moves_method_base_b(t_node *curr,
								t_node *closest);
int							calc_moves_method_c(t_node *curr, t_node *closest);
int							calc_moves_method_d(t_node *curr, t_node *closest);

// Sort Utils
t_node						*find_smallest(t_list *lst);
void						update_index(t_list *stack);
t_node						*find_closest_lowest(t_list *stack_a, t_node *node);
int							find_max(int a, int b);
int							find_min(int a, int b);

// Stack Inits
void						stacks_init_string_split(int argc, char *argv[],
								t_stacks *stacks);
t_stacks					*init_stacks(void);
void						init_sort_stacks(t_stacks *stacks);

#endif
