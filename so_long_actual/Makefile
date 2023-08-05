NAME = capy_adventure

CC = cc

FLAGS = -Wall -Wextra -Werror #add flags after $(CC) when testing add $(FLAGS)

SRC = get_next_line.c main.c init.c utils.c \
checker.c map_build.c queue.c utils2.c movement.c \
exit.c floodfill.c utils3.c

OBJ :=$(SRC:.c=.o)

$(NAME): $(OBJ)
	cc $(OBJ) -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC)  -Iinclude -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all