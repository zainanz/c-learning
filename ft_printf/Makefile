C_FLAGS = -Wall -Werror -Wextra
SRC_DIR = src
SRC = ${wildcard ${SRC_DIR}/*.c}
OBJ = ${SRC:.c=.o}
INC = includes/
HEADER = ${INC}/libft.h ${INC}/ft_printf.h
NAME = libftprintf.a

all: ${NAME} 

${NAME}: ${OBJ}
	make -C libft
	cp libft/libft.a .
	mv libft.a ${NAME}
	ar -rc ${NAME} ${OBJ}
gcc:
	gcc ${C_FLAGS} -I. src/ft_printf.c $(NAME)

%.o: %.c ${HEADER}
	cc ${C_FLAGS} -c -I${INC} $< -o $@

clean:
	rm ${SRC_DIR}/*.o
fclean: clean
	rm ${NAME}
re: fclean all
