SRC= main.c	hooks.c colors_bitshift.c fractol.c utils.c pixels.c display_action.c
BONUS= main_bonus.c hooks_bonus.c colors_bitshift.c fractol_bonus.c utils.c pixels.c display_action.c dragoncrv.c 
OBJ= $(addprefix src/,$(SRC:.c=.o))
OBJ_BONUS= $(addprefix src/,$(BONUS:.c=.o))
NAME= fract-ol
NAME_BONUS= fract-ol-bonus
CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -lft -L./libft -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	make -C libft
	$(CC) $^ -Lmlx_linux -lmlx_Linux -L/usr/lib -lft -L./libft -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME_BONUS)

%.o: %.c
	$(CC)  $(CFLAGS) -I./Include -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
fclean: clean
	make fclean -C libft
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
re: fclean all
