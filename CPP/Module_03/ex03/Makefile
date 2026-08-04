# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zali <zali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 10:18:54 by zali              #+#    #+#              #
#    Updated: 2026/08/04 03:32:51 by zali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 	= c++
C_FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp main.cpp
HEADER = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
OBJ = $(SRC:.cpp=.o)
NAME = diamondtrap 

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