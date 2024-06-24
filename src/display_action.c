/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:20:08 by pierre            #+#    #+#             */
/*   Updated: 2024/06/24 19:36:30 by pbeyloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	apply_action(t_vars *vars, int keycode)
{
	if (keycode == XK_Escape)
		free_vars(vars, 0);
	if (keycode == XK_a)
		vars->precision -= 10;
	if (keycode == XK_s)
		vars->precision += 10;
	if (keycode == XK_Right)
		vars->moveviewx += 20;
	if (keycode == XK_Left)
		vars->moveviewx -= 20;
	if (keycode == XK_Down)
		vars->moveviewy += 20;
	if (keycode == XK_Up)
		vars->moveviewy -= 20;
	if (keycode == XK_c)
		vars->color = vars->color + 65000;
	if (keycode == XK_g)
		vars->color = 0x0000FF00;
	if (keycode == XK_b)
		vars->color = 0x000000FF;
	if (keycode == XK_r)
		vars->color = 0x00FF0000;
	pixel_setter(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_data->img, 0, 0);
}
