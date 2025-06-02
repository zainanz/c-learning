/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:07:10 by zali              #+#    #+#             */
/*   Updated: 2025/06/01 15:33:49 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_stacks	*init_stacks(void)
{
	static t_stacks	stacks;

	if (!stacks.stack_a)
	{
		stacks.stack_a = lst_init();
		if (!stacks.stack_a)
		{
			perror("Malloc error");
			exit(EXIT_FAILURE);
		}
	}
	if (!stacks.stack_b)
	{
		stacks.stack_b = lst_init();
		if (!stacks.stack_b)
		{
			free(stacks.stack_a);
			perror("MALLOC ERROR");
			exit(EXIT_FAILURE);
		}
	}
	return (&stacks);
}

int	str_end(char *s)
{
	int	i;

	i = 0;
	while (s[i] != ' ')
		if (s[i++] == '\0')
			return (-1);
	return (i);
}

void	sort_stacks(t_stacks *stacks)
{
	int	i;
	int	b_size;

	i = 0;
	b_size = stacks->stack_b->size;
	while (i < b_size)
	{
		if (i < 3)
		{
			push_to_from(stacks->stack_a, stacks->stack_b);
		}
		else
			write(1, "pb\n", 3);
		i++;
	}
}

static t_node	*validate_create_node(t_stacks *stacks, char *str)
{
	long	nbr;
	t_node	*curr;

	nbr = ft_atol(str);
	curr = stacks->stack_b->tail;
	if (!valid_num(str))
		handle_str_error(stacks);
	if (nbr > INT_MAX || nbr < INT_MIN)
		handle_str_error(stacks);
	while (curr)
	{
		if (curr->value == nbr)
			handle_str_error(stacks);
		curr = curr->prev;
	}
	return (create_node(nbr));
}

void	stacks_init_string_split(int argc, char *argv[], t_stacks *stacks)
{
	int	i;
	int	j;
	int	str_len;

	str_len = 0;
	i = 0;
	j = 1;
	while (j < argc)
	{
		while (argv[j][i] == ' ')
			i++;
		str_len = str_end(argv[j] + i);
		if (str_len != -1)
			argv[j][i + str_len] = '\0';
		if (argv[j][i])
			push_node(stacks->stack_b, validate_create_node(stacks, argv[j]
					+ i));
		if (str_len == -1 || !argv[j][i])
		{
			j++;
			i = 0;
			continue ;
		}
		i += str_len + 1;
	}
}
