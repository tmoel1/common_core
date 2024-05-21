# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoeller <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 12:53:17 by tmoeller          #+#    #+#              #
#    Updated: 2023/11/07 12:53:25 by tmoeller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SCRS	=	ft_printf.c		\
			print_char.c	\
			print_hex.c		\
			print_number.c	\
			print_pointer.c	\
			print_string.c	\

NAME = libftprintf.a
OBJS = ${SCRS:.c=.o}
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
