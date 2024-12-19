CC = cc
CFLAGS  = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utlis.c
OBJ = ${SRC:.c=.o}

BONUS_SRC = get_next_line_bonus.c get_next_line_utlis_bonus.c
BONUS_OBJ = ${BONUS_SRC:.c=.o}

NAME = GetNextLine

all: ${NAME}

${NAME} : ${OBJ}
	ar rcs ${NAME} ${OBJ}

bonus:
	ar rcs ${NAME} {BONUS_OBJ}

clean:
	rm -rf ${OBJ} ${BONUS_OBJ}

fclean:
	rm -rf ${NAME}

re: fclean clean

.PHONY: all clean fclean re bonus
