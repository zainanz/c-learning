CC = gcc
C_FLAGS = -Wall -Werror -Wextra
LIB = libft.a
HEADER = libft.h
SRC = $(wildcard *.c)
OBJ = ${SRC:.c=.o}
ODIR = $(addprefix ${O_DIR}, ${OBJ})
BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJ = ${BONUS_SRC:.c=.o}

all: ${LIB}

bonus: ${BONUS_OBJ}
	ar -rc ${LIB} ${BONUS_OBJ}

${LIB}: ${ODIR}
	ar -rc ${LIB} ${OBJ}

%.o: %.c ${HEADER}
	${CC} ${C_FLAGS} -c -I. $< -o $@

clean: 
	rm *.o

fclean: clean
	rm ${LIB}
.PHONY: all clean fclean
