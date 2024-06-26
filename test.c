/* #include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h> */
#include "Include/libft.h"
#include <stdio.h>
	typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void drawvline(t_data *data, int x, int y, char c)
{
	int i;

	i = 1;

	while (i <= 10)
	{
		if (c == 'U')
			y--;
		else if (c == 'D')
			y++;
		else if (c == 'L')
			x--;
		else if (c == 'R')
			x++;
		my_mlx_pixel_put(data, x, y , 0x0000FF00);
		i++;
	}
}
void	ft_swap(char *str)
{
	int	strlen;
	int	i;
	char	temp;
	if (!str)
		return ;
	if (!ft_strcmp(str, ""))
		return ;
	strlen = ft_strlen(str);
	i = 0;
	while (i < strlen / 2)
	{
		temp = str[i];
		str[i] = str[strlen - i - 1];
		str[strlen - 1 - i] = temp;
		i++;
	}	
}
void	ft_strrplc(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (*str)
	{
		if (*str == 'R')
			*str = 'L';
		else if (*str == 'L')
			*str = 'R';
		str++;
	}
}

char	*get_dragon(int i, char *str)
{
	char *temp;
	char *temp2;

	if (i == 0)
		return (str);
	else
	{
		temp = ft_strjoin(str, "R");
		ft_swap(str);
		ft_strrplc(str);
		temp2 = ft_strjoin(temp, str);
		free(str);
		free(temp);
		get_dragon(i - 1, temp2);
	}
}

int	main(void)
{
/* 	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	drawvline(&img, 1920/2, 1080/2, 'D');
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0); */
	char *str = malloc(sizeof(char) * 2);
	str[0] = 'R';
	str[1] = 0;
	char *new = get_dragon(20, str);
	printf("%s\n", new);
	free(new);

	return (0);
}




