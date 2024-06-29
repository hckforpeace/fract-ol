/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:18:20 by pierre            #+#    #+#             */
/*   Updated: 2024/06/29 23:42:36 by pierre           ###   ########.fr       */
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

int	get_offsetx(int x, double xb, t_vars *params)
{
	double	xz;
	int		offsetx;

	xz = ((x + params->moveviewx) - (params->win_x / 2)) * params->scale;
	offsetx = (int)((xb - xz) / params->scale);
	return (offsetx);
}

int	get_offsety(int y, double yb, t_vars *params)
{
	double	yz;
	int		offsety;

	yz = ((params->win_y / 2) - (y + params->moveviewy)) * params->scale;
	offsety = (int)((yb - yz) / params->scale);
	return (offsety);
}
