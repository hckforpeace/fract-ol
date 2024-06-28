/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:53:32 by pierre            #+#    #+#             */
/*   Updated: 2024/06/28 13:11:24 by pbeyloun         ###   ########.fr       */
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
	if (button == 4)
	{
		params->moveviewx = 0;
		params->moveviewx = 0;
		params->scale *= 1.05;
		pixel_setter(params);
		mlx_put_image_to_window(params->mlx, params->win,
			params->img_data->img, 0, 0);
	}
	if (button == 5)
	{
		params->moveviewx = 0;
		params->moveviewx = 0;
		params->scale /= 1.05;
		pixel_setter(params);
		mlx_put_image_to_window(params->mlx, params->win,
			params->img_data->img, 0, 0);
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
