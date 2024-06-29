/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:11:47 by pierre            #+#    #+#             */
/*   Updated: 2024/06/29 18:34:03 by pbeyloun         ###   ########.fr       */
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
	double	xz;
	double	yz;
	double	xb;
	double	yb;
	int		offsetx;
	int		offsety;
	xb = ((x + params->moveviewx) - (params->win_x / 2)) * params->scale;
	yb = ((params->win_y / 2) - (y + params->moveviewy)) * params->scale;
	if (button == 4)
	{
		// ZOOM OUT
		params->scale *= 1.5;
		xz = ((x + params->moveviewx) - (params->win_x / 2)) * params->scale;
		yz = ((params->win_y / 2) - (y + params->moveviewy)) * params->scale;
		offsetx = (int)((xb - xz) / params->scale);
		offsety = (int)((yb - yz) / params->scale);
		params->moveviewx += offsetx;
		params->moveviewy -= offsety; 
	}
	else if (button == 5)
	{
		// ZOOM IN
		params->scale /= 1.5;
		xz = ((x + params->moveviewx) - (params->win_x / 2)) * params->scale;
		yz = ((params->win_y / 2) - (y + params->moveviewy)) * params->scale;
		offsetx = (int)((xb - xz) / params->scale);
		offsety = (int)((yb - yz) / params->scale);
		params->moveviewx += offsetx;
		params->moveviewy -= offsety;
	}
	pixel_setter(params);
	mlx_put_image_to_window(params->mlx, params->win,
		params->img_data->img, 0, 0); 
	return (1);
}
/* int	mousemoves(int button, int x, int y, t_vars *params)
{
    double x_centered;
    double y_centered;
    double new_scale;
    double zoom_factor;

    zoom_factor = 1.5;

    // Center the coordinates relative to the middle of the window
    x_centered = (x + params->moveviewx) - (params->win_x / 2);
    y_centered = (params->win_y / 2) - (y + params->moveviewy);

    if (button == 4) // ZOOM OUT
    {
        new_scale = params->scale / zoom_factor;
        params->moveviewx += (x_centered * (new_scale - params->scale));
        params->moveviewy += (y_centered * (new_scale - params->scale));
        params->scale = new_scale;
        printf("ZOOM OUT x: %d, y: %d, x_centered: %f, y_centered: %f\n", x, y, x_centered, y_centered);
    }
    else if (button == 5) // ZOOM IN
    {
        new_scale = params->scale * zoom_factor;
        params->moveviewx += (x_centered * (new_scale - params->scale));
        params->moveviewy += (y_centered * (new_scale - params->scale));
        params->scale = new_scale;
        printf("ZOOM IN x: %d, y: %d, x_centered: %f, y_centered: %f\n", x, y, x_centered, y_centered);
    }

    pixel_setter(params);
    mlx_put_image_to_window(params->mlx, params->win, params->img_data->img, 0, 0);
    return (1);
} */



static int	close_page(void *params)
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
