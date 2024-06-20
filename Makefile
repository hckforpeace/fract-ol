SRC= main.c	hooks.c colors_bitshift.c mandelbrot.c
OBJ= $(addprefix src/,$(SRC:.c=.o))
NAME= fract-ol
# CFLAGS= -Wall -Wextra -Werror

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -lft -L./libft -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC)  $(CFLAGS) -I./Include -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJ)
fclean: clean
	make fclean -C libft
	rm -f $(NAME)
