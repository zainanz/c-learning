# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zali <zali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/06 05:18:49 by zali              #+#    #+#              #
#    Updated: 2026/08/06 05:21:28 by zali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRC = Animal.cpp Cat.cpp Dog.cpp main.cpp
HEADER = Animal.hpp Dog.hpp Cat.hpp
OBJ = $(SRC:.cpp=.o)
NAME = animal

all: ${NAME}

${NAME}: ${OBJ}
	${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

.PHONY: all re fclean cleanz