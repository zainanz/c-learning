# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/01 21:51:41 by zali              #+#    #+#              #
#    Updated: 2025/06/01 21:56:13 by zali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
SRC = calc_moves.c clean_and_error.c list_manipulation.c list_sort_utils.c\
	  num_utils.c push_swap_cmds.c stacks_init.c calc_moves_methods.c\
	  linked_list_and_node.c list_sort.c main.c push_swap_cmds2.c\
	  sort_methods.c top_selected_nodes.c
OBJ = ${SRC:.c=.o}
HEADER = push_swap.h

${NAME}: ${OBJ} ${HEADER}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}
%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -I. -c $< -o $@
clean:
	rm -f *.o
fclean: clean
	rm -f ${NAME}
re: fclean re
.PHONY: re fclean clean
