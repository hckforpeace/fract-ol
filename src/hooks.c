/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:53:32 by pierre            #+#    #+#             */
/*   Updated: 2024/06/22 18:25:25 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_windows(int keycode, t_vars *params)
{
	
	if (keycode == ESC)
	{
		mlx_destroy_window(params->mlx, params->win);
		mlx_loop_end(params->mlx);
		ft_printf("Program terminated\n");
		free_vars(params);
	}
	if (keycode == 115)
	{
		params->precision += 10;
		pixel_setter(params);
		mlx_put_image_to_window(params->mlx, params->win, params->img_data->img, 0, 0);	
	}
	if (keycode == 113)
	{
		params->precision -= 10;
		pixel_setter(params);
		mlx_put_image_to_window(params->mlx, params->win, params->img_data->img, 0, 0);	
	}
	if (keycode == 114)
	{
		fprintf(stderr, "keycode %f\n", params->scale);
		params->scale *= 2; 
		pixel_setter(params);
		mlx_put_image_to_window(params->mlx, params->win, params->img_data->img, 0, 0);
	}
	return (1);
}

int	mousemoves(int button, int x, int y, t_vars *params)
{
	if (button == 4)
	{
		params->scale *= 1.5;
		pixel_setter(params);
		mlx_put_image_to_window(params->mlx, params->win, params->img_data->img, 0, 0);
	}
	if (button == 5)
	{
		params->scale /= 1.5;
		pixel_setter(params);
		mlx_put_image_to_window(params->mlx, params->win, params->img_data->img, 0, 0);
	}
	return (1);
}

int	close_page(void *params)
{
	t_vars *tep = (t_vars *)(params);
	mlx_destroy_window(tep->mlx, tep->win);
	mlx_loop_end(tep->mlx);
	ft_printf("Program terminated\n");
	free_vars(params);
	return (0);
}
void	set_hooks(t_vars *data)
{
	mlx_key_hook(data->win, close_windows, data);
	mlx_hook(data->win, 17, 0, close_page, data);
	mlx_mouse_hook(data->win, mousemoves, data);
}

