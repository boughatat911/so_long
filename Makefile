# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 17:55:16 by nbougrin          #+#    #+#              #
#    Updated: 2025/02/14 10:12:06 by nbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address

MLX_DIR = mlx_linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext -lm

FILES	= Mandatory/so_long.c Mandatory/parsing/fun_1.c Mandatory/parsing/fun_2.c \
			Mandatory/utils_libft/ft_split.c Mandatory/utils_libft/get_next_line.c Mandatory/utils_libft/get_next_line_utils.c \
			Mandatory/utils_libft/ft_itoa.c \
			Mandatory/mlx/mlx.c Mandatory/mlx/fun_mlx.c

OBJ	= $(FILES:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJ) $(MLX_LIB)
		cc $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS)

Mandatory/%.o	: Mandatory/%.c Mandatory/so_long.h Makefile
		cc $(CFLAGS) -c $< -o $@

$(MLX_LIB)	:
		@make -C $(MLX_DIR)

clean	:
		rm -f $(OBJ)

fclean	: clean
		rm -f $(NAME)
		make -C $(MLX_DIR) clean

re		: fclean all
