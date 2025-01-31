NAME=libc.a

CC=cc

CFLAGS=-Wall -Wextra -Werror

AR=ar cr

RM=rm -f

SRCS= ft_split.c fun_linked_list.c get_next_line.c get_next_line_utils.c utils.c

OBJS= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o : %.c libc.h
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all