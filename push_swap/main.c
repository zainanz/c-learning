/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:16:46 by zali              #+#    #+#             */
/*   Updated: 2025/06/01 15:34:09 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;

	if (argc == 1)
		return (0);
	stacks = init_stacks();
	if (argc == 2)
		stacks_init_string_split(argc, argv, stacks);
	else
		stacks_init_argvs(argc, argv, stacks);
	three_sort(stacks->stack_a);
	perform_sort(stacks->stack_a, stacks->stack_b);
	send_top(stacks->stack_a, find_smallest(stacks->stack_a));
	print_lst(stacks->stack_a);
	clean_up_stacks(init_stacks());
	return (0);
}

	/*while (argc - 1 > 0)
	{
		if (!valid_num(argv[argc - 1]))
			return (display_error(stacks->stack_a, stacks->stack_b));
		if (stacks->stack_a->size == 3)
			break ;
		node = create_node(ft_atoi(argv[argc - 1]));
		push_node(stacks->stack_a, node);
		argc--;
	}
	three_sort(stacks->stack_a);
	while (len < argc)
	{
		node = create_node(ft_atoi(argv[len]));
		push_node(stacks->stack_b, node);
		write(1, "pb\n", 3);
		len++;
	}*/
/*
	printf(" -- BEFORE SORT -- ");
	printf("- STACK A (SIZE=%i)-\n", stack_a->size);
	print_lst(stack_a);
	printf("- STACK B (SIZE=%i)-\n", stack_b->size);
	print_lst(stack_b);
	printf("\n\n\n\n\n");
	printf("\n\n\n -- AFTER SORT -- ");
	printf("- STACK A (SIZE=%i)-\n", stack_a->size);
	print_lst(stack_a);
	printf("- STACK B (SIZE=%i)-\n", stack_b->size);
	print_lst(stack_b);
	print_lst(stack_a);
*/

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
