/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:53:32 by pierre            #+#    #+#             */
/*   Updated: 2024/06/24 02:14:14 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_events(int keycode, t_vars *params)
{
	if (keycode == ESC)
		free_vars(params, 0);
	if (keycode == 115)
		lprecision(params);
	if (keycode == 113)
		mprecision(params);
	return (1);
}

int	mousemoves(int button, int x, int y, t_vars *params)
{
	if (button == 4)
		zoom_in(params);
	if (button == 5)
		zoom_out(params);
	return (1);
}

int	close_page(void *params)
{
	ft_printf("Program terminated\n");
	free_vars(params, 0);
	return (0);
}

void	set_hooks(t_vars *data)
{
	mlx_mouse_hook(data->win, mousemoves, data);
	mlx_hook(data->win, 17, 0, close_page, data);
	mlx_key_hook(data->win, key_events, data);
}
