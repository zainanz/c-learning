CC = gcc
C_FLAGS = -Wall -Werror -Wextra
LIB = libft.a
HEADER = libft.h
SRC = $(wildcard *.c)
OBJ = ${SRC:.c=.o}
O_DIR = bin/
ODIR = $(addprefix ${O_DIR}, ${OBJ})
all: ${LIB}

${LIB}: ${ODIR}
	ar -rc ${LIB} ${ODIR}
${ODIR}: bin

bin: 
	mkdir ${O_DIR}

${O_DIR}%.o: %.c ${HEADER}
	${CC} ${C_FLAGS} -c -I. $< -o $@

clean: 
	rm -rf ${O_DIR}

fclean: clean
	rm ${LIB}
.PHONY: all clean fclean
