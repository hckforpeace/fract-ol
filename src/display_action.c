/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:20:08 by pierre            #+#    #+#             */
/*   Updated: 2024/06/24 02:11:54 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	apply_action(t_vars *vars, int keycode)
{
	if (keycode == ESC)
		free_vars(vars, 0);
	if (keycode == 115)
		vars->precision -= 10;
	if (keycode == 97)
		vars->precision += 10;
	if (keycode == 65361)
		vars->moveviewx += 5;
	if (keycode == 65363)
		vars->moveviewx -= 5;
	if (keycode == 65362)
		vars->moveviewy += 5;
	if (keycode == 65364)
		vars->moveviewy -= 5;
	pixel_setter(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_data->img, 0, 0);
}
