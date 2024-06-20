/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:41:05 by pierre            #+#    #+#             */
/*   Updated: 2024/06/20 11:42:41 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_vars *data, double x, double y, double precision)
{
	double	gx;
	double	gy;
	double	module;

	gx = x - (data->win_x / 2);
	gy = y - (data->win_y / 2);
	module = get_module(gx * precision, gy * precision);
	if (module > 2)
	{
		my_mlx_pixel_put(data->img_data, x, y, 0x00000000);
	}
	else if (get_nextfract(gx * precision, gy * precision, 20))
		my_mlx_pixel_put(data->img_data, x, y, 0x00FFFFFF);
	else
		my_mlx_pixel_put(data->img_data, x, y, 0x00000000);
}

int	get_nextfract(double cx, double cy, int iteration)
{
	double	zx;
	double	zy;
	double	temp_zx;
	double	temp_zy;
	double	result;

	zx = 0;
	zy = 0;
	while (iteration > 0)
	{
		temp_zx = zx;
		temp_zy = zy;
		zx = pow(temp_zx, 2) - pow(temp_zy, 2);
		zy = (2 * temp_zx * temp_zy);
		if (get_module((zx + cx), (zy + cy)) > 2)
			return (0);
		zx = zx + cx;
		zy = zy + cy;
		iteration--;
	}
	return (1);
}

double	get_module(double x, double y)
{
	return (sqrt(pow(x, 2) + pow(y, 2)));
}