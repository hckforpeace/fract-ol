/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:11:47 by pierre            #+#    #+#             */
/*   Updated: 2024/06/30 00:19:51 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_events(int keycode, t_vars *params)
{
	if ((keycode == XK_Escape || keycode == XK_r || keycode == XK_a
			|| keycode == XK_s || keycode == XK_c || keycode == XK_Left
			|| keycode == XK_Right || keycode == XK_g || keycode == XK_b
			|| keycode == XK_Down || keycode == XK_Up)
		&& (ft_strcmp(params->frc_name, "Dragon") != 0))
		apply_action(params, keycode);
	else if (keycode == XK_Escape)
		apply_action(params, keycode);
	return (1);
}

int	mousemoves(int button, int x, int y, t_vars *params)
{
	double	xb;
	double	yb;
	int		offsetx;
	int		offsety;

	xb = ((x + params->moveviewx) - (params->win_x / 2)) * params->scale;
	yb = ((params->win_y / 2) - (y + params->moveviewy)) * params->scale;
	if (button == 5)
	{
		params->scale *= 1.5;
		offsetx = get_offsetx(x, xb, params);
		offsety = get_offsety(y, yb, params);
		zoom_in_mouse(offsetx, offsety, params);
	}
	else if (button == 4 && params->zoom_times < 35)
	{
		params->scale /= 1.5;
		offsetx = get_offsetx(x, xb, params);
		offsety = get_offsety(y, yb, params);
		zoom_in_mouse(offsetx, offsety, params);
	}
	printf("count zoom\n");
	return (1);
}

static int	close_page(void *params)
{
	free_vars(params, 0);
	return (0);
}

void	set_hooks(t_vars *data)
{
	if (ft_strcmp(data->frc_name, "Dragon"))
		mlx_mouse_hook(data->win, mousemoves, data);
	mlx_hook(data->win, 17, 0, close_page, data);
	mlx_key_hook(data->win, key_events, data);
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
	free(instr);
	my_mlx_pixel_put(data->img_data, data->win_x / 2,
		data->win_y / 2, 0x00FF0000);
}
