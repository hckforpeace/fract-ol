/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:53:32 by pierre            #+#    #+#             */
/*   Updated: 2024/06/19 12:03:58 by pierre           ###   ########.fr       */
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
	}
	return (1);
}

int	mousemoves(int button, int x, int y, void *params)
{
	ft_printf("button: %d, x: %d, y: %d\n", button,  x, y);
	return (0);
}

int	close_page(void *params)
{
	t_vars *tep = (t_vars *)(params);
	mlx_destroy_window(tep->mlx, tep->win);
	mlx_loop_end(tep->mlx);
	ft_printf("Program terminated\n");
	return (0);
}