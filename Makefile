# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 17:55:16 by nbougrin          #+#    #+#              #
#    Updated: 2025/02/01 19:07:02 by nbougrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	so_long

CFLAGS	=	-Wall -Wextra -Werror

FILES	=	Mandatory/so_long.c Mandatory/parsing/fun_1.c Mandatory/parsing/fun_2.c \
			Mandatory/utils_libft/ft_split.c Mandatory/utils_libft/get_next_line.c Mandatory/utils_libft/get_next_line_utils.c
OBJ	=	$(FILES:.c=.o)

all		: $(NAME)

$(NAME)		: $(OBJ)
		cc $(CFLAGS) $(OBJ) -o $(NAME) 

Mandatory/%.o	: Mandatory/%.c Mandatory/so_long.h
		cc $(CFLAGS) -c $< -o $@

clean		:
		rm -f $(OBJ)

fclean		: clean
		rm -f $(NAME)

re		: fclean all