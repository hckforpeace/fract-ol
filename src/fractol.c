/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:41:05 by pierre            #+#    #+#             */
/*   Updated: 2024/06/22 14:39:52 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	setbase(t_vars *data, double x, double y)
{
	double	module;
	int		*loops;
	float		idx;

	loops = (int *)malloc(sizeof(int));
	if (!loops)
		return (1);
	*loops = 0;
	data->frctl->x = (x - (data->win_x / 2)) * data->scale;
	data->frctl->y = ((data->win_y / 2) - y) * data->scale;
	module = get_module(data->frctl->x, data->frctl->y);
	if (module > 4)
		my_mlx_pixel_put(data->img_data, x, y, add_shade(0, 0xF0FF0020));
	else if (get_nextfract(data, loops))
		my_mlx_pixel_put(data->img_data, x, y, 0x00000000);
	else
	{
		idx = *loops / data->scale;
		my_mlx_pixel_put(data->img_data, x, y, add_shade(idx, 0x00F24361));
	}
	free(loops);
	return (0);
}

int	get_nextfract(t_vars *data, int	*loops)
{
	if (!ft_strcmp(data->frc_name, "Mandelbrot"))
		return (mandelbrot(data, loops));
	else
		return (Julia(data, loops));
}

int	Julia(t_vars *data, int	*loops)
{
	double	temp_zx;
	double	temp_zy;
	double	i;

	i = 0;
	while (i < data->precision)
	{
		temp_zx = data->frctl->x;
		temp_zy = data->frctl->y;
		data->frctl->x = pow(temp_zx, 2) - pow(temp_zy, 2);
		data->frctl->y = (2 * temp_zx * temp_zy);
	if (get_module((data->frctl->x + data->frctl->cx), (data->frctl->y + data->frctl->cy)) > 4)
		{
			*loops = i;
			return (0);
		}
		data->frctl->x = data->frctl->x + data->frctl->cx;
		data->frctl->y = data->frctl->y + data->frctl->cy;
		i++;
	}
	return (1);
}

int	mandelbrot(t_vars *data, int *loops)
{
	double	zx;
	double	zy;
	double	temp_zx;
	double	temp_zy;
	double	i;

	zx = 0;
	zy = 0;
	i = 0;
	while (i < data->precision)
	{
		temp_zx = zx;
		temp_zy = zy;
		zx = pow(temp_zx, 2) - pow(temp_zy, 2);
		zy = (2 * temp_zx * temp_zy);
	if (get_module((zx + data->frctl->x), (zy + data->frctl->y)) > 4)
		{
			*loops = i;
			return (0);
		}
		zx = zx + data->frctl->x;
		zy = zy + data->frctl->y;
		i++;
	}
	return (1);
}

double	get_module(double x, double y)
{
	return (sqrt(pow(x, 2) + pow(y, 2)));
}