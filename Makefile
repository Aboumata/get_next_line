CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c main.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

NAME = get_next_line.a

all: $(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all