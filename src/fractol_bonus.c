/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:41:05 by pierre            #+#    #+#             */
/*   Updated: 2024/06/26 19:24:35 by pbeyloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	setbase(t_vars *data, double x, double y)
{
	double		module;
	int			*loops;
	float		idx;

	loops = (int *)malloc(sizeof(int));
	if (!loops)
		return (1);
	*loops = 0;
	data->frctl->x = ((x + data->moveviewx) - (data->win_x / 2)) * data->scale;
	data->frctl->y = ((data->win_y / 2) - (y + data->moveviewy)) * data->scale;
	module = get_module(data->frctl->x, data->frctl->y);
	if (module > 4)
		my_mlx_pixel_put(data->img_data, x, y, 0);
	else if (getnextfract(data, loops))
		my_mlx_pixel_put(data->img_data, x, y, data->color);
	else
	{
		idx = *loops / (1.0 / data->precision);
		my_mlx_pixel_put(data->img_data, x, y, add_shade(idx, data->color));
	}
	free(loops);
	return (0);
}

int	getnextfract(t_vars *data, int	*loops)
{
	if (!ft_strcmp(data->frc_name, "Mandelbrot"))
		return (mandelbrot(data, loops));
	else if (!ft_strcmp(data->frc_name, "BS"))
		return (burning_ship(data, loops));
	else
		return (julia(data, loops));
}

int	burning_ship(t_vars *data, int *loops)
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
		temp_zx = fabs(zx);
		temp_zy = fabs(zy);
		zx = pow(temp_zx, 2) - pow(temp_zy, 2);
		zy = (-2 * temp_zx * temp_zy);
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

int	julia(t_vars *data, int *loops)
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
		if (get_module((data->frctl->x + data->frctl->cx),
				(data->frctl->y + data->frctl->cy)) > 4)
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

void	dragon_curve(t_vars *data)
{
	char	*instr;
	char	*fst;
	int		i;
	char	c;

	data->dragx = data->win_x / 2;
	data->dragy = data->win_y / 2;
	i = 1;
	fst = (char *)malloc(sizeof(char) * 2);
	fst[0] = 'R';
	fst[1] = 0;
	instr = get_dragon(20, fst);
	c = 'D';
	drawline(data, data->dragx, data->dragy, 'D');
	while (instr[i] && data->dragx < data->win_x && data->dragx > 0
		&& data->dragy < data->win_y && data->dragy > 0)
	{
		c = display_case(c, instr[i], data);
		i++;
	}
	my_mlx_pixel_put(data->img_data, data->win_x / 2,
		data->win_y / 2, 0x00FF0000);
}
