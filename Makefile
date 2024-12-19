CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c
OBJ = ${SRC:.c=.o}

BONUS_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c
BONUS_OBJ = ${BONUS_SRC:.c=.o}

NAME = GetNextLine

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}

bonus: ${BONUS_OBJ}
	ar rcs ${NAME} ${BONUS_OBJ}

clean:
	rm -rf ${OBJ} ${BONUS_OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
