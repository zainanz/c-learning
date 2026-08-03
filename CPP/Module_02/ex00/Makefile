# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zali <zali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/01 00:39:06 by zali              #+#    #+#              #
#    Updated: 2026/08/01 00:44:27 by zali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=c++
C_FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = Fixed.cpp main.cpp
HEADER = Fixed.hpp
OBJ = $(SRC:.cpp=.o)
NAME = fixed

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${C_FLAGS} ${OBJ} -o ${NAME}

%.o: %.cpp ${HEADER}
	${CC} ${C_FLAGS} -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

.PHONY: all re fclean clean