# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zali <zali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/19 14:15:51 by zali              #+#    #+#              #
#    Updated: 2025/07/20 17:57:02 by zali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS = 
NAME = ./a.out
SRC = runcmd.c main.c string_utils.c safe_utils.c execute.c parse.c struct_inits.c runcmd_utils.c
OBJ = ${SRC:.c=.o}
HEADER = minishell.h
SUP_FILE = .readline.supp
all: ${NAME}

${NAME}: ${OBJ} ${HEADER}
	${CC} ${CFLAGS} ${OBJ} -lreadline -o ${NAME}

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@ 

clean:
	rm -f ${OBJ}

valrun: ${NAME}
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --suppressions=${SUP_FILE} \
         ./${NAME}

fclean: clean
	rm -f ${NAME}
