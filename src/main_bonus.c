/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:10:42 by pierre            #+#    #+#             */
/*   Updated: 2024/06/30 14:48:24 by pbeyloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 23:46:11 by pierre            #+#    #+#             */
/*   Updated: 2024/06/24 01:04:24 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	display_info(0);
	if (argc == 2 && !ft_strcmp(argv[1], "Mandelbrot"))
		jober(argv[1], 0, 0);
	else if (argc == 2 && !ft_strcmp("Dragon", argv[1]))
		jober(argv[1], 0, 0);
	else if (argc == 2 && !ft_strcmp("BS", argv[1]))
		jober(argv[1], 0, 0);
	else if (argc == 4 && !ft_strcmp(argv[1], "Julia"))
	{
		if (!is_double(argv[2]) || !is_double(argv[3]))
			ft_printf("\n\n****   wrong double parameters   ****\n\n");
		else
			jober("Julia", ft_atof(argv[2]), ft_atof(argv[3]));
	}
	return (0);
}

int	jober(char	*frctl, double x, double y)
{
	t_vars	*data;

	data = init_vars(1920.0, 1080.0, "FRACTOL", frctl);
	data->frctl->cx = x;
	data->frctl->cy = y;
	data->moveviewx = 0;
	data->moveviewy = 0;
	data->dragx = data->win_x / 2;
	data->dragy = data->win_y / 2;
	data->xorg = 0;
	data->yorg = 0;
	if (!ft_strcmp("Dragon", frctl))
		dragon_curve(data);
	else if (pixel_setter(data) < 0)
		free_vars(data, 1);
	mlx_put_image_to_window(data->mlx, data->win, data->img_data->img,
		data->xorg, data->yorg);
	set_hooks(data);
	mlx_loop(data->mlx);
	return (0);
}

t_vars	*init_vars(int size_x, int size_y, char *win_name, char *frct)
{
	t_vars	*data;

	data = (struct s_vars *)malloc(sizeof(struct s_vars));
	if (!data)
		fexit_data(data);
	data->img_data = (struct s_data *)malloc(sizeof(struct s_data));
	if (!data->img_data)
		fexit_data(data);
	data->precision = 250;
	data->scale = 1.0 / 350.0;
	data->color = 0x00FF0000;
	data->frctl = (struct s_fractal *)malloc(sizeof(struct s_fractal));
	if (!data->frctl)
		fexit_data(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, size_x, size_y, win_name);
	data->img_data->img = mlx_new_image(data->mlx, size_x, size_y);
	data->img_data->addr = mlx_get_data_addr(data->img_data->img,
			&data->img_data->bits_per_pixel,
			&data->img_data->line_length, &data->img_data->endian);
	data->win_x = size_x;
	data->win_y = size_y;
	data->frc_name = frct;
	data->zoom_times = 0;
	return (data);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
