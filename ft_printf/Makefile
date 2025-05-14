C_FLAGS = -Wall -Werror -Wextra
SRC_DIR = src
SRC = ${wildcard ${SRC_DIR}/*.c}
OBJ = ${SRC:.c=.o}
INC = ./includes/
HEADER = ${INC}/ft_printf.h
NAME = libftprintf.a

all: ${NAME}

${NAME}: ${OBJ}
	ar -rc ${NAME} ${OBJ}
gcc:
	gcc ${C_FLAGS} -I. src/ft_printf.c $(NAME)

%.o: %.c ${HEADER}
	cc ${C_FLAGS} -c -I${INC} $< -o $@

clean:
	rm -f ${OBJ}
fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all fclean clean re
