HEADER	=	phonebook.hpp

NAME	=	phonebook

SRCS	=	phonebook.cpp Person.class.cpp

CL		=	clang++

R		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME): ${HEADER} ${SRCS}
	${CL} ${CFLAGS} ${SRCS} -o $(NAME)

clean:
			${R} $(NAME)

re:			clean all

.PHONY:		all clean re
