# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zali <zali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 10:18:54 by zali              #+#    #+#              #
#    Updated: 2025/10/13 18:41:46 by zali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 	= c++
C_FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = ClapTrap.cpp ScavTrap.cpp main.cpp
HEADER = ClapTrap.hpp ScavTrap.hpp
OBJ = $(SRC:.cpp=.o)
NAME = scavtrap 

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