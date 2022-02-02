# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbenkhar <dbenkhar@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 12:04:48 by dbenkhar          #+#    #+#              #
#    Updated: 2022/02/02 21:54:13 by dbenkhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long

SRC=	so_long.c init_error_check.c world_init.c \
		list_utils.c free_data.c check_validmap.c\

LIBDIR= ./libft
LIBFT= libft/libft.a
MLXDIR= ./minilibx
MLX= minilibx/libmlx.a

GNL= gnl/*.c

CC= gcc
FLAGS= -Wall -Werror -Wextra -g3

OS := $(shell uname)

CFLAGS_LINUX= $(FLAGS) $(MLX) -lXext -lX11 -lm -lz

CFLAGS_MACOS= $(FLAGS) $(MLX) -L/usr/X11/lib -lXext -lX11 -lm -lz

ifeq ($(OS), Darwin)
CFLAGS= $(CFLAGS_MACOS)
else
CFLAGS= $(CFLAGS_LINUX)
endif

all: $(NAME)

$(NAME):
	make -C $(LIBDIR)
	make -C $(MLXDIR)
	$(CC) $(SRC) $(GNL) $(LIBFT) $(CFLAGS) -o $(NAME)

clean:
	@make clean -C $(LIBDIR)

fclean:
	@make fclean -C $(LIBDIR)
	@make clean -C $(MLXDIR)
	@rm -rf *.dSYM
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
