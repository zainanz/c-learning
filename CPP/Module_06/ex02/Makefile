CXX = c++
CXX_FLAGS = -Wall -Werror -Wextra -std=c++98
CXXFLAGS = 
SRC = Serializer.cpp main.cpp
O = obj/
OBJ = ${SRC:%.cpp=${O}%.o}
DEP = ${OBJ:.o=.d}
NAME = serialize 

all: ${NAME}

${NAME}: ${OBJ}
	${CXX} ${CXXFLAGS} $^ -o $@ 

$(O):
	@mkdir -p $@

${OBJ}: | ${O}
${OBJ}: ${O}%.o : %.cpp
	${CXX} ${CXXFLAGS} -MMD -MP -c $< -o $@

clean:
	rm -rf ${O}

fclean: clean
	rm -rf ${NAME}
re: fclean all 

-include ${DEP}