# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/11 11:39:22 by zali              #+#    #+#              #
#    Updated: 2026/06/11 11:39:57 by zali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
C_FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = Zombie.cpp main.cpp randomChump.cpp newZombie.cpp
HEADER = Zombie.hpp
OBJ = ${SRC:.cpp=.o}
NAME = zombie 

${NAME}: ${OBJ}
	${CC} ${OBJ} -o ${NAME}
%.o: %.cpp ${HEADER}
	${CC} ${C_FLAGS} -c -I. $< -o $@
clean:
	rm -f ${OBJ}
fclean: clean
	rm -f ${NAME}
re: fclean ${NAME}
