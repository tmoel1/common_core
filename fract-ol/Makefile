# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 09:34:17 by tmoeller          #+#    #+#              #
#    Updated: 2024/06/14 09:37:53 by tmoeller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable Names
FRACTOL_NAME = fractol

# Source Files
FRACTOL_SRC = fractol.c

# Object Files
FRACTOL_OBJ = ${FRACTOL_SRC:.c=.o}

# Library Settings
LIBDIR = libft_ext
LIBNAME = ft_ext
LIBA = lib${LIBNAME}.a
LIB_INC = -I${LIBDIR}

# MiniLibX Settings
MLX_DIR = minilibx
MLX_LIB = -L${MLX_DIR} -lmlx
MLX_INC = -I${MLX_DIR}
MLX_FLAGS = -lXext -lX11 -lm -lz # Adjust these flags as necessary for your system!!!!!!!!!!

# Compiler + Flags
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror ${LIB_INC} ${MLX_INC}

# Default rule for .c to .o conversion
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# Default target
all: ${LIBDIR}/${LIBA} ${FRACTOL_NAME}

# Build the library
${LIBDIR}/${LIBA}:
	${MAKE} -C ${LIBDIR}

# Build the fractol executable
${FRACTOL_NAME}: ${FRACTOL_OBJ} ${LIBDIR}/${LIBA}
	${CC} ${CFLAGS} -o ${FRACTOL_NAME} ${FRACTOL_OBJ} -L${LIBDIR} -l${LIBNAME} ${MLX_LIB} ${MLX_FLAGS}

# Clean the object files
clean:
	${RM} ${FRACTOL_OBJ}
	${MAKE} -C ${LIBDIR} clean

# Clean everything
fclean: clean
	${RM} ${FRACTOL_NAME}
	${MAKE} -C ${LIBDIR} fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re

