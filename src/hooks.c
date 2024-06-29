/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:53:32 by pierre            #+#    #+#             */
/*   Updated: 2024/06/30 00:06:36 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_events(int keycode, t_vars *params)
{
	if (keycode == XK_Escape || keycode == XK_a || keycode == XK_s)
		apply_action(params, keycode);
	return (1);
}

int	mousemoves(int button, int x, int y, t_vars *params)
{
	if (button == 5)
	{
		params->scale *= 1.1;
		zoom_in_mouse(0.0, 0.0, params);
	}
	if (button == 4 && params->zoom_times < 35)
	{
		params->scale /= 1.1;
		zoom_in_mouse(0.0, 0.0, params);
	}
	return (1);
}

static int	close_page(void *params)
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
