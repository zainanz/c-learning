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
#include <stdio.h>

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

static void	sort_stacks(t_stacks *stacks)
{
	int	i;
	int	b_size;

	i = 0;
	b_size = stacks->stack_b->size;
	while (i < b_size)
	{
		if (i < 3)
			push_to_from(stacks->stack_a, stacks->stack_b);
		else
			write(1, "pb\n", 3);
		i++;
	}
}

void	stacks_init_string_split(int argc, char *argv[], t_stacks *stacks)
{
	int	i;
	int	str_len;

	str_len = 0;
	i = 0;
	while (argv[1][i])
	{
		while (argv[1][i] == ' ')
			i++;
		if (!argv[1][i])
			return ;
		str_len = str_end(argv[1] + i);
		if (str_len != -1)
			argv[1][str_len] = '\0';
		if (!valid_num(argv[1] + i))
			handle_str_error(stacks);
		push_node(stacks->stack_b, create_node(ft_atoi(argv[1] + i)));
		if (str_len == -1)
			break ;
		i += str_len + 1;
	}
	sort_stacks(stacks);
}

int	stacks_init_argvs(int argc, char *argv[], t_stacks *stacks)
{
	int			len;

	len = 1;
	while (argc - 1 > 0)
	{
		if (!valid_num(argv[argc - 1]))
			return (handle_str_error(stacks), 1);
		if (stacks->stack_a->size == 3)
			break ;
		push_node(stacks->stack_a, create_node(ft_atoi(argv[argc - 1])));
		argc--;
	}
	while (len < argc)
	{
		push_node(stacks->stack_b, create_node(ft_atoi(argv[len])));
		write(1, "pb\n", 3);
		len++;
	}
	return (0);
}
