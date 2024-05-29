NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
# LIBFT = libft/libft.a
SRCS = push_swap.c utils.c lib_utils.c stack_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME) $(LIBFT)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re