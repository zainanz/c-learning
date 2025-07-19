# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zali <zali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/19 14:15:51 by zali              #+#    #+#              #
#    Updated: 2025/07/19 14:25:54 by zali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS = 
NAME = ./a.out
SRC = runcmd.c main.c utils.c display_utils.c
OBJ = ${SRC:.c=.o}
HEADER = minishell.h
all: ${NAME}

${NAME}: ${OBJ} ${HEADER}
	${CC} ${CFLAGS} ${OBJ} -lreadline -o ${NAME}

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@ 

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}
