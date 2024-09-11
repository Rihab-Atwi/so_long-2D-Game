NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -L./mlx -lmlx -L./mlx -lXext -lX11 -lm

SRC =   free_exit.c \
        player_movements.c \
        hooks.c \
        check_map_0.c \
        check_map_1.c \
        get_next_line_utils.c \
        get_next_line.c \
        main.c \
        so_long_utils_0.c \
        so_long_utils_1.c \
        render_fts.c \
        image_handle.c

OBJ = $(SRC:.c=.o)

EXEC = $(NAME)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all
