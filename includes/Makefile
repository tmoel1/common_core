# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoeller <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 16:00:07 by tmoeller          #+#    #+#              #
#    Updated: 2024/04/15 16:00:35 by tmoeller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(shell find src/ft_printf src/libft src/get_next_line -name "*.c")
NAME = my_lib.a
CFLAGS = -Wall -Werror -Wextra 
OBJS = ${SRCS:.c=.o}
LIBC = ar rcs
CC = cc

RM = rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${LIBC} ${NAME} ${OBJS}

all: 	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
