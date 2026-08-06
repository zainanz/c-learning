# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zali <zali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/06 05:18:49 by zali              #+#    #+#              #
#    Updated: 2026/08/06 09:08:51 by zali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRC = Animal.cpp Cat.cpp Dog.cpp main.cpp Brain.cpp
HEADER = Animal.hpp Dog.hpp Cat.hpp Brain.hpp
OBJ = $(SRC:.cpp=.o)
NAME = animal

all: ${NAME}

${NAME}: ${OBJ}
	${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME}

%.o: %.cpp ${HEADER}
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

.PHONY: all re fclean clean