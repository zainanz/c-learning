# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/14 11:57:59 by zali              #+#    #+#              #
#    Updated: 2025/06/14 11:58:00 by zali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = error_close.c pipex.c pipex_utils.c ft_strjoin.c ft_split.c
OBJ = ${SRC:.c=.o}
HEADER = pipex.h
NAME = pipex

all: ${NAME}

${NAME}: ${OBJ} ${HEADER}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}
%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@
clean: 
	rm -f *.o
fclean: clean
	rm -f ${NAME}
re: fclean all
.PHONY: re fclean clean
