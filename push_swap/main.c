/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:16:46 by zali              #+#    #+#             */
/*   Updated: 2025/05/31 08:50:55 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_node	*node;
	int		len;
	
	node = NULL;
	len = 1;
	stack_a = lst_init();
	stack_b = lst_init();
	while (argc - 1 > 0)
	{
		if (!valid_num(argv[argc - 1]))
			return (display_error());
		if (stack_a->size == 3)
			break ;
		node = create_node(ft_atoi(argv[argc - 1]));
		push_node(stack_a, node);
		argc--;
	}
	three_sort(stack_a);
	while (len < argc) // pperforms multiple pbs
	{
		node = create_node(ft_atoi(argv[len]));
		push_node(stack_b, node);
		len++;
	}
	printf(" -- BEFORE SORT -- ");
	printf("- STACK A (SIZE=%i)-\n", stack_a->size);
	print_lst(stack_a);
	printf("- STACK B (SIZE=%i)-\n", stack_b->size);
	print_lst(stack_b);
	perform_sort(stack_a, stack_b);
	printf(" -- AFTER SORT -- ");
	printf("- STACK A (SIZE=%i)-\n", stack_a->size);
	print_lst(stack_a);
	printf("- STACK B (SIZE=%i)-\n", stack_b->size);
	print_lst(stack_b);
	//  Cleanup
	clear_lst(stack_a);
	clear_lst(stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}

/*
int	main(int argc, char *argv[])
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	i = argc - 1;
	stack_a = lst_init();
	stack_b = lst_init();
	if (argc < 1)
		return (0);
	while (i > 0)
		push_node(stack_a, create_node(ft_atoi(argv[i--])));
	
	// TEST CASES 

	// PUSH NODES
	push_node(stack_b, create_node(5));
	push_node(stack_b, create_node(20));
	push_node(stack_b, create_node(15));

	printf("\n\n\t== PUSH NODE == ");
	printf("\n---------STACK B-----------\n");
	print_lst(stack_b);
	printf("---------------------------\n");
	
	// PUSH TO FROM
	printf("\n\n\t== PUSH TO FROM == ");
	push_to_from(stack_a, stack_b);
	push_to_from(stack_a, stack_b);
	push_to_from(stack_a, stack_b);
	push_to_from(stack_b, stack_a);
	push_to_from(stack_b, stack_a);
	push_to_from(stack_b, stack_a);
	printf("\n---STACK A---\n");
	print_lst(stack_a);
	printf("\n---STACK B---\n");
	print_lst(stack_b);
	printf("-----------------\n");

	printf("\n\n\t== SHIFT UP == \n");
	printf("ORIGINAL STACK_B:\n");
	print_lst(stack_b);
	printf("SHIFT UP STACK_B:\n");
	shift_up(stack_b);
	print_lst(stack_b);
	shift_up(stack_b);
	shift_up(stack_b);
	printf("SHIFT UP STACK_B:x2\n");
	print_lst(stack_b);
	printf("SHIFT DOWN STACK_B:\n");
	shift_down(stack_b);
	print_lst(stack_b);
	printf("SHIFT DOWN STACK_A:\n");
	print_lst(stack_a);

	// Ensuring no leaks!
	clear_lst(stack_a);
	clear_lst(stack_b);
	print_lst(stack_b);
	free(stack_a);
	free(stack_b);
	return (1);
}
*/
