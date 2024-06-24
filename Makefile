SRC= main.c	hooks.c colors_bitshift.c fractol.c utils.c pixels.c display_action.c
BONUS= main_bonus.c hooks_bonus.c colors_bitshift.c fractol_bonus.c utils.c pixels.c display_action.c
OBJ= $(addprefix src/,$(SRC:.c=.o))
OBJ_BONUS= $(addprefix src/,$(BONUS:.c=.o))
NAME= fract-ol
# CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

bonus: $(OBJ_BONUS)
	make -C libft
	$(CC) $(OBJ_BONUS) -Lmlx_linux -lmlx_Linux -L/usr/lib -lft -L./libft -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -lft -L./libft -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC)  $(CFLAGS) -I./Include -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
fclean: clean
	make fclean -C libft
	rm -f $(NAME)
re: fclean all
