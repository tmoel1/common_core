# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 11:33:27 by tmoeller          #+#    #+#              #
#    Updated: 2024/05/21 17:16:04 by tmoeller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
PRINTF = ft_printf

SCRS	=	sources/error_handling.c	\
			sources/init_a_to_b.c	\
			sources/init_b_to_a.c	\
			sources/init_tools.c	\
			sources/p_s_split.c	\
			sources/push_swap.c	\
			sources/push.c	\
			sources/reverse_rotate.c	\
			sources/rotate.c	\
			sources/sort_3.c	\
			sources/stack_init.c	\
			sources/stack_tools.c	\
			sources/swap.c	\
			sources/turk_algo.c	\

PRINTF_SCRS = ft_printf/ft_printf.c		\
			ft_printf/print_char.c	\
			ft_printf/print_hex.c		\
			ft_printf/print_number.c	\
			ft_printf/print_pointer.c	\
			ft_printf/print_string.c	\

OBJS = ${SCRS:.c=.o}
PRINTF_OBJS = ${PRINTF_SCRS:.c=.o}
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${PRINTF}: ${PRINTF_OBJS}
		ar rcs lib${PRINTF}.a ${PRINTF_OBJS}

${NAME}: ${PRINTF} ${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L. -l${PRINTF}

clean:
		${RM} ${OBJS} ${PRINTF_OBJS}

fclean: clean
		${RM} ${NAME} lib${PRINTF}.a

re: fclean all

.PHONY : all clean fclean re
