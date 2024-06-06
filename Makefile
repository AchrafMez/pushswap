NAME = push_swap

CC = cc
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
# CFLAGS = -Wall -Wextra -Werror
# -fsanitize=address -g 
# LIBFT = libft/libft.a
SRCS = push_swap.c utils.c lib_utils.c stack_utils.c check.c instructions.c sort.c index.c
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
