/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:18:20 by pierre            #+#    #+#             */
/*   Updated: 2024/06/22 14:24:36 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	pixel_setter(t_vars *data)
{
	double	x;
	double	y;

	x = 0;
	y = 0;
	while (x < data->win_x)
	{
		while (y < data->win_y)
		{
			if (setbase(data, x, y) == 1)
				return (-1);
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	add_shade(float shade, int color)
{
	return (create_trgb(get_t(color) * shade, get_r(color) * shade,
			get_g(color) * shade, get_b(color) * shade));
}
