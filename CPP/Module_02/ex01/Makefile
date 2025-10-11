CC = c++
C_FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = Fixed.cpp main.cpp 
HEADER = Fixed.hpp
OBJ = ${SRC:.cpp=.o}
NAME = fixed

${NAME}: ${OBJ}
	${CC} ${OBJ} -o ${NAME}
%.o: %.cpp ${HEADER}
	${CC} ${C_FLAGS} -c -I. $< -o $@
clean:
	rm -f ${OBJ}
fclean: clean
	rm -f ${NAME}