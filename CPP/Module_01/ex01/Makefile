CC = c++
C_FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = Zombie.cpp main.cpp zombieHorde.cpp
HEADER = Zombie.hpp
OBJ = ${SRC:.cpp=.o}
NAME = zstory

${NAME}: ${OBJ}
	${CC} ${OBJ} -o ${NAME}
%.o: %.cpp ${HEADER}
	${CC} ${C_FLAGS} -c -I. $< -o $@
clean:
	rm -f ${OBJ}
fclean: clean
	rm -f ${NAME}