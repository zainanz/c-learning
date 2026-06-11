# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/11 11:52:31 by zali              #+#    #+#              #
#    Updated: 2026/06/11 11:52:39 by zali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
C_FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = main.cpp
OBJ = ${SRC:.cpp=.o}
NAME = main

${NAME}: ${OBJ}
	${CC} ${OBJ} -o ${NAME}
%.o: %.cpp ${HEADER}
	${CC} ${C_FLAGS} -c -I. $< -o $@
clean:
	rm -f ${OBJ}
fclean: clean
	rm -f ${NAME}
re: fclean ${NAME};
