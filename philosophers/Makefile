CC = clang
C_FLAG = -Wall -Werror -Wextra
SRC = ${wildcard *.c}
OBJ = ${SRC:.c=.o}
NAME = philo
all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${C_FLAG} ${OBJ} -o ${NAME}
%.o: %.c 
	${CC} ${C_FLAGS} -c -I. $< -o $@

clean:
	rm -rf ${OBJ}
fclean: clean
	rm -rf ${NAME}
max:
	${CC} ${C_FLAG} ${SRC} -D MAX_LIMIT=${limit} -o ./philo
f: 
	${CC} $(SRC) -fsanitize=thread -g -pthread -o ./philo
