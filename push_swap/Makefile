# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 11:33:27 by tmoeller          #+#    #+#              #
#    Updated: 2024/05/21 14:00:28 by tmoeller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SCRS	=	sources/error_handling.c	\
			sources/init_a_to_b.c	\
			sources/init_b_to_a.c	\
			sources/init_tools.c	\
			sources/p_s_split.c		\
			sources/push_swap.c		\
			sources/push.cc		\
			sources/reverse_rotate.c	\
			sources/rotate.c		\
			sources/sort_3.c		\
			sources/stack_tools.c	\
			sources/swap.c		\
			sources/turk_algo.c		\
			ft_printf/*.c		\

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

