#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct t_node
{
	int 		data;
	struct t_node	*next;
}	s_node;

typedef struct t_stack
{
	struct t_node	*head;
	struct t_node	*tail;
	struct t_node	*size;
}	s_stack;

void	*safe_malloc(int size)
{
	void	*ptr;
	ptr = malloc(size);
	if (!ptr)
	{
		perror("malloc error");
		exit(1);
	}
}

s_stack	*init_stack()
{
	s_stack	*stack = safe_malloc(sizeof(s_stack));
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

s_node	*init_node(int num)
{
	s_node	*node;

	node = safe_malloc(sizeof(s_node));
	node->data = num;
	node->next = NULL;
}

void	print_stack(s_stack *stack)
{
	s_node *node = stack->head;
	while (node)
	{
		printf("%i ", node->data);
		node = node->next;
	}
	printf("\n");
}

void	push_stack(s_stack *stack, int i)
{
	s_node *node= init_node(i);
	if (!stack->head && !stack->tail)
	{
		stack->head = node;
		stack->tail = node;
		stack->size++;
	}
	else
	{
		stack->tail->next = node;
		stack->tail = stack->tail->next;
		stack->size++;
	}
}

void	pop_stack(s_stack *stack)
{
	s_node *node= stack->head;
	if (stack->head == stack->tail)
	{
		free(stack->head);
		stack->head = NULL;
		stack->tail = NULL;
		stack->size--;
		return ;
	}
	if (!stack->tail && !stack->head)
	{
		printf("empty already\n");
		return ;
	}
	// printf("tail: %p - %i\n", stack->tail, stack->tail->data);
	while (node && node->next != stack->tail)
		node = node->next;
	// printf("%ptr - %i\n", node, node->data);
	// printf("%ptr - %i\n", node->next, node->next->data);
	// printf("2nd. %i\n", node->next->data);
	// printf("3nd. %p(TAIL)\n", node->next->next);
	// if (node->next->next->next)
	// 	printf("4th. %i\n", node->next->next->next->data);
	// else
	// 	printf("end\n");
	// printf("\n");
	// if (!node->next)
	// {
		// printf("node next is nill\n");
	// }
	// printf("STACK->TAIL: %i \nNODE: %i", stack->tail->data, node->data);
	free(stack->tail);
	stack->tail = node;
	stack->tail->next = NULL;
	stack->size--;
	// printf("tail is %p, %i\n", stack->tail, stack->tail->data);
}

void	subset(int *set, int size, int index, s_stack *stack)
{
	int idx;

	if (index == size)
	{
		print_stack(stack);
		return ;
	}
	push_stack(stack, set[index]);
	subset(set, size, index + 1, stack);
	pop_stack(stack);
	idx = index + 1;
	while (index + 1 < size && set[idx] == set[idx - 1])
		idx++;
	subset(set, size, idx, stack);
}

int	main(void)
{
	s_stack	*stack = init_stack();
	int set[] = {1, 2, 2};
	subset(set, 3, 0, stack);
}
