NAME = get_next_line
CC = cc
FLAGS = -g -Wall -Werror -Wextra #-D BUFFER_SIZE=10

# Remove wildcard then finish all .c

SRC = get_next_line.c get_next_line_utils.c main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
