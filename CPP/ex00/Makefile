# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zali <zali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 13:33:50 by zali              #+#    #+#              #
#    Updated: 2025/09/23 13:47:25 by zali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
SRC = megaphone.cpp
OBJ = ${SRC:.cpp=.o}
NAME = megaphone


${NAME}: ${OBJ}
	${CC} ${OBJ} -o ${NAME}
	@echo -e "\033[32m$./${NAME} complied.\033[0m"

%.o: %.cpp
	${CC} -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}