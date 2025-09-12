CC = clang
C_FLAG = -Wall -Werror -Wextra
SRC = *.c
all:
	${CC} ${SRC} -o ./philo
f: 
	${CC} $(SRC) -fsanitize=thread -g -pthread -o ./philo
