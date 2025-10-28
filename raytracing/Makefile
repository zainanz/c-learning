# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zali <zali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24 13:06:20 by zali              #+#    #+#              #
#    Updated: 2025/10/26 13:11:31 by zali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
# C_FLAGS = -Wall -Werror -Wextra
SRC = main.c 
OBJ = ${SRC:.c=.o}
HEADER = raytracing.h
LIBS =  libmlx.a
LIBHEAD = minilibx-linux/mlx.h
NAME = rt 

${NAME}: ${OBJ}
	${CC} ${C_FLAGS} ${OBJ} ${LIBS} -I./${LIBHEAD} -lXext -lX11 -lm -o ${NAME}
%.o: %.c
	${CC} ${C_FLAGS} -c $< -o $@
clean: 
	rm -f ${OBJ}
fclean: clean
	rm -f ${NAME}
