# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zali <zali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 10:18:54 by zali              #+#    #+#              #
#    Updated: 2025/10/19 16:00:05 by zali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
C_FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = Dog.cpp Cat.cpp Animal.cpp Brain.cpp Wrong.cpp main.cpp
HEADER = Dog.hpp Cat.hpp Animal.hpp Brain.hpp Wrong.hpp main.hpp
OBJ = ${SRC:.cpp=.o}
NAME = animal

${NAME}: ${OBJ}
	${CC} ${C_FLAGS} ${OBJ} -o ${NAME}

%.o: %.cpp ${HEADER}
	${CC} ${C_FLAGS} -c -I. $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

