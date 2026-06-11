# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/11 12:02:45 by zali              #+#    #+#              #
#    Updated: 2026/06/11 12:03:01 by zali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
C_FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
HEADER = Zombie.hpp HumanA.hpp HumanB.hpp
OBJ = ${SRC:.cpp=.o}
NAME = hweap

${NAME}: ${OBJ}
	${CC} ${OBJ} -o ${NAME}
%.o: %.cpp ${HEADER}
	${CC} ${C_FLAGS} -c -I. $< -o $@
clean:
	rm -f ${OBJ}
fclean: clean
	rm -f ${NAME}
re: fclean ${NAME}
