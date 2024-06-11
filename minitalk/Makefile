# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 10:56:11 by tmoeller          #+#    #+#              #
#    Updated: 2024/06/11 15:00:38 by tmoeller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable Names
SERVER_NAME = server
CLIENT_NAME = client

# Source Files
SERVER_SRC = server.c
CLIENT_SRC = client.c

# Object Files
SERVER_OBJ = ${SERVER_SRC:.c=.o}
CLIENT_OBJ = ${CLIENT_SRC:.c=.o}

# Library Settings
LIBDIR = libft_ext
LIBNAME = ft_ext
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
all: ${LIBDIR}/${LIBA} ${SERVER_NAME} ${CLIENT_NAME}

# Build the library
${LIBDIR}/${LIBA}:
	${MAKE} -C ${LIBDIR}

# Build the server executable
${SERVER_NAME}: ${SERVER_OBJ} ${LIBDIR}/${LIBA}
	${CC} ${CFLAGS} -o ${SERVER_NAME} ${SERVER_OBJ} -L${LIBDIR} -l${LIBNAME}

# Build the client executable
${CLIENT_NAME}: ${CLIENT_OBJ} ${LIBDIR}/${LIBA}
	${CC} ${CFLAGS} -o ${CLIENT_NAME} ${CLIENT_OBJ} -L${LIBDIR} -l${LIBNAME}

# Clean the object files
clean:
	${RM} ${SERVER_OBJ} ${CLIENT_OBJ}
	${MAKE} -C ${LIBDIR} clean

# Clean everything
fclean: clean
	${RM} ${SERVER_NAME} ${CLIENT_NAME}
	${MAKE} -C ${LIBDIR} fclean


# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
