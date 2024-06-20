/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 23:46:11 by pierre            #+#    #+#             */
/*   Updated: 2024/06/20 11:43:54 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	main(int argc, char **argv, char **envp)
{
	t_vars	*data;

	data = init_vars(1920, 1080, "FRACTOL");
	// set_bckclr(data->img_data, 1920, 1080, 0x00FFFFFF);
	pixel_setter(data);
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

t_vars	*init_vars(int size_x, int size_y, char *win_name)
{
	t_vars	*data;

	data = (struct s_vars*)malloc(sizeof(struct s_vars));
	data->img_data = (struct s_data*)malloc(sizeof(struct s_data));

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, size_x, size_y, win_name);
	data->img_data->img = mlx_new_image(data->mlx, size_x, size_y);
	data->img_data->addr = mlx_get_data_addr(data->img_data->img, &data->img_data->bits_per_pixel, 
	&data->img_data->line_length, &data->img_data->endian);
	data->win_x = size_x;
	data->win_y = size_y;
	return (data);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void	set_hooks(t_vars *data)
{
	mlx_key_hook(data->win, close_windows, data);
	mlx_hook(data->win, 17, 0, close_page, data);
}

void pixel_setter(t_vars *data)
{
	double	x;
	double	y;

	x = 0;
	y = 0;
	while (x < data->win_x)
	{
		while (y < data->win_y)
		{
			mandelbrot(data, x, y, 1.0 / 400.0);
			y++;
		}
		y = 0;
		x++;
	}
}
