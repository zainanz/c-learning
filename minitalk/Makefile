CC = cc
CFLAGS = -Wall -Werror -Wextra
SERVER_SRC = server.c server_handler_utils.c str_struct_server.c utils.c
CLIENT_SRC = client.c utils.c
HEADER = minitalk.h
SERVER_OBJ = ${SERVER_SRC:.c=.o}
CLIENT_OBJ= ${CLIENT_SRC:.c=.o}
SERVER_NAME = server
CLIENT_NAME = client

all: ${SERVER_NAME} ${CLIENT_NAME} 

${SERVER_NAME}: ${SERVER_OBJ}
	${CC} ${CFLAGS} ${SERVER_OBJ} -o ${SERVER_NAME}

${CLIENT_NAME}: ${CLIENT_OBJ}
	${CC} ${CFLAGS} ${CLIENT_OBJ} -o ${CLIENT_NAME}

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@
clean: 
	rm -f ${SERVER_OBJ} ${CLIENT_OBJ}
fclean: clean
	rm -f ${SERVER_NAME} ${CLIENT_NAME}
re: fclean all
