NAME = get_next_line
NAME_BONUS = get_next_line_bonus

CC = cc
FLAGS = -g -Wall -Werror -Wextra #-D BUFFER_SIZE=10

# Remove wildcard then finish all .c

SRC = get_next_line.c get_next_line_utils.c main.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus

