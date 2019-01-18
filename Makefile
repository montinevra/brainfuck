NAME = brainfuck
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = brainfuck.c
OBJ = $(SRC:.c=.o) 

.PHONY: all clean fclean re
	

all: $(NAME)
	

$(NAME): $(SRC)
	$(CC) -o$(NAME) $(SRC) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
