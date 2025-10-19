# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zali <zali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 10:18:54 by zali              #+#    #+#              #
#    Updated: 2025/10/19 14:12:52 by zali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
C_FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = main.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp AMateria.cpp ICharacter.cpp IMateriaSource.cpp
HEADER = Ice.hpp Cure.hpp Character.hpp MateriaSource.hpp AMateria.hpp ICharacter.hpp IMateriaSource.hpp
OBJ = ${SRC:.cpp=.o}
NAME = materia 

${NAME}: ${OBJ}
	${CC} ${OBJ} -o ${NAME}
%.o: %.cpp ${HEADER}
	${CC} ${C_FLAGS} -c -I. $< -o $@
clean:
	rm -f ${OBJ}
fclean: clean
	rm -f ${NAME}