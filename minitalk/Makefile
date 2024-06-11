# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 10:56:11 by tmoeller          #+#    #+#              #
#    Updated: 2024/06/11 11:17:59 by tmoeller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

# Source Files
SCRS = server.c \
       client.c \

OBJS = ${SCRS:.c=.o}

# Library Settings
LIBDIR = libft_ext
LIBNAME = libft_ext
LIBA = lib${LIBNAME}.a
LIB_INC = -I${LIBDIR}

# Compiler + Flags
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

# Default rule for .c to .o conversion
.c.o:
	${CC} ${CFLAGS} ${LIB_INC} -c $< -o ${<:.c=.o}

# Default target
all: ${LIBDIR}/${LIBA} ${NAME}

# Build the library
${LIBDIR}/${LIBA}:
	${MAKE} -C ${LIBDIR}

# Build the main executable
${NAME}: ${OBJS} ${LIBDIR}/${LIBA}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${LIBDIR} -l${LIBNAME}

# Clean the object files
clean:
	${RM} ${OBJS}
	${MAKE} -C ${LIBDIR} clean

# Clean everything
fclean: clean
	${RM} ${NAME}
	${RM} ${LIBDIR}/${LIBA}

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
