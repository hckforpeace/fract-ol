/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:11:47 by pierre            #+#    #+#             */
/*   Updated: 2024/06/24 19:34:18 by pbeyloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_events(int keycode, t_vars *params)
{
	if (keycode == XK_Escape || keycode == XK_r || keycode == XK_a || keycode == XK_s || keycode == XK_c
		|| keycode == XK_Left || keycode == XK_Right || keycode == XK_g
		|| keycode == XK_b || keycode == XK_Down || keycode == XK_Up)
		apply_action(params, keycode);
	fprintf(stderr, "keycode: %d\n", keycode);
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

int	close_page(void *params)
{
	free_vars(params, 0);
	return (0);
}

void	set_hooks(t_vars *data)
{
	mlx_mouse_hook(data->win, mousemoves, data);
	mlx_hook(data->win, 17, 0, close_page, data);
	mlx_key_hook(data->win, key_events, data);
}
