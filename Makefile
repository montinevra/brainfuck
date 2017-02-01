NAME = brainfuck
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Llibft -lft
SRC = brainfuck.c

.PHONY: all clean fclean re
	

all: $(NAME)
	

$(NAME): $(SRC) libft/libft.a
	$(CC) -o$(NAME) $(SRC) $(CFLAGS)

clean:


fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all


libft/libft.a:
	make -C ./libft

