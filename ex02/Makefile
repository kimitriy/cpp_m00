# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rburton <rburton@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 11:32:38 by rburton           #+#    #+#              #
#    Updated: 2021/06/30 04:11:17 by rburton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= account

HEADER		= Account.hpp

SRC 		= 	tests.cpp \

OBJS		= ${SRC:.cpp=.o}

CPP			= clang++

FLAGS		= -g -Wall -Wextra -Werror -std=c++98

RM			= rm -f

all:		${NAME}

.c.o:		
				${CPP} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS} ${HEADER}
				${CPP} ${FLAGS} -o ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}
		${RM} ${LIB}

re:		fclean all

.phony: all clean re