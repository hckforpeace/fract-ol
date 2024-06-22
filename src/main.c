/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 23:46:11 by pierre            #+#    #+#             */
/*   Updated: 2024/06/22 14:38:59 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc == 2 && !ft_strcmp(argv[1], "Mandelbrot"))
		jober(argv[1], 0, 0);
	else if (argc == 4 && !ft_strcmp(argv[1], "Julia"))
	{
		printf("x: %f, y: %f\n", ft_atof(argv[2]), ft_atof(argv[3]));
		jober("Julia", ft_atof(argv[2]), ft_atof(argv[3]));
	}
	else
		display_info(0, NULL);
	return (0);
}

int	jober(char	*frctl, double x, double y)
{
	t_vars	*data;

	data = init_vars(1920.0, 1080.0, "FRACTOL", frctl);
	data->frctl->cx = x;
	data->frctl->cy = y;
	if (pixel_setter(data) < 0)
		display_info(1, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_data->img, 0, 0);
	set_hooks(data);
	mlx_loop(data->mlx);
	return (0);
}

void	set_bckclr(t_data *data, int dimx, int dimy, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < dimx)
	{
		while (y < dimy)
		{
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}

t_vars	*init_vars(int size_x, int size_y, char *win_name, char *frct)
{
	t_vars	*data;

	data = (struct s_vars*)malloc(sizeof(struct s_vars));
	if (!data)
		display_info(1, data);
	data->img_data = (struct s_data*)malloc(sizeof(struct s_data));
	if (!data->img_data)
		display_info(1, data);
	data->precision = 100;
	data->scale = 1.0 / 350.0;
	data->frctl = (struct s_fractal*)malloc(sizeof(struct s_fractal));
	if (!data->frctl)
		display_info(1, data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, size_x, size_y, win_name);
	data->img_data->img = mlx_new_image(data->mlx, size_x, size_y);
	data->img_data->addr = mlx_get_data_addr(data->img_data->img, &data->img_data->bits_per_pixel, 
	&data->img_data->line_length, &data->img_data->endian);
	data->win_x = size_x;
	data->win_y = size_y;
	data->frc_name = frct;
	return (data);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
