CC = cc
C_FLAG = -Wall -Werror -Wextra
SRC = ${wildcard *.c}
OBJ = ${SRC:.c=.o}
NAME = philo
limit = 200

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${C_FLAG} ${OBJ} -o ${NAME}
%.o: %.c 
	${CC} ${C_FLAG} -c -I. $< -o $@ -D MAX_LIMIT=${limit}
clean:
	rm -rf ${OBJ}
fclean: clean
	rm -rf ${NAME}
re: fclean ${NAME}
.PHONY: max
