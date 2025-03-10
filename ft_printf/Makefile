CC = gcc
C_FLAGS = -Wall -Werror -Wextra
SRC = ${wildcard *.c}
OBJ = ${SRC:.c=.o}
HEADER = libft.h ft_printf.h
LIB_INC = libft.a

all: lib

compile: ${OBJ}
	${CC} ${C_FLAGS} ${OBJ} -I. ${LIB_INC}

lib: ${OBJ} ${HEADER}
	ar -rc libft_printf.a ${OBJ} ${LIB_INC}

%.o: %.c ${HEADER}
	${CC} ${C_FLAGS} -c -I. $< -o $@

clean:
	rm ${OBJ}

fclean: clean
	rm libft_printf.a
