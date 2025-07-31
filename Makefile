NAME = get_next_line
CC = cc
FLAGS = -Wall -Werror -Wextra

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

.o: .c
	$(CC) $(FLAGS) -c $< -o $@

clear:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clear fclear re
