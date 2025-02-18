# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 17:55:16 by nbougrin          #+#    #+#              #
#    Updated: 2025/02/18 19:31:04 by nbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
Bonus_NAME	= so_long_bonus

CFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address

MLX_DIR = mlx_linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext -lm

MANDATORY_FILES = Mandatory/so_long.c Mandatory/parsing/fun_1.c Mandatory/parsing/fun_2.c \
			Mandatory/utils_libft/ft_split.c Mandatory/utils_libft/get_next_line.c Mandatory/utils_libft/get_next_line_utils.c \
			Mandatory/utils_libft/ft_itoa.c \
			Mandatory/mlx/mlx.c Mandatory/mlx/fun_mlx.c

BONUS_FILES = Bonus/so_long_bonus.c Bonus/parsing/fun_1_bonus.c Bonus/parsing/fun_2_bonus.c \
			Bonus/utils_libft/ft_split_bonus.c Bonus/utils_libft/get_next_line_bonus.c \
			Bonus/utils_libft/get_next_line_utils_bonus.c \
			Bonus/utils_libft/ft_itoa_bonus.c Bonus/mlx/fun_bonus.c \
			Bonus/mlx/mlx_bonus.c Bonus/mlx/fun_mlx_bonus.c Bonus/mlx/mlx_enemy.c

OBJ	= $(MANDATORY_FILES:.c=.o)
BONUS_OBJ = $(BONUS_FILES:.c=.o)

all	: $(NAME)

$(NAME)	: $(OBJ) $(MLX_LIB)
		cc $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS)

$(Bonus_NAME) : $(BONUS_OBJ) $(MLX_LIB)
		cc $(CFLAGS) $(BONUS_OBJ) -o $(Bonus_NAME) $(MLX_FLAGS)

Mandatory/%.o	: Mandatory/%.c Mandatory/so_long.h Makefile
		cc $(CFLAGS) -c $< -o $@

Bonus/%.o	: Bonus/%.c Bonus/so_long_bonus.h Makefile
		cc $(CFLAGS) -c $< -o $@

$(MLX_LIB)	:
		@make -C $(MLX_DIR)

clean	:
		rm -f $(OBJ) $(BONUS_OBJ)

fclean	: clean
		rm -f $(NAME) $(Bonus_NAME)
		make -C $(MLX_DIR) clean

re		: fclean all

bonus	: $(Bonus_NAME)
