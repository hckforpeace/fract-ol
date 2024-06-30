/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeyloun <pbeyloun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:12:24 by pierre            #+#    #+#             */
/*   Updated: 2024/06/30 17:00:51 by pbeyloun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_vars(t_vars *vars, int status)
{
	mlx_destroy_image(vars->mlx, vars->img_data->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars->frctl);
	free(vars->img_data);
	free(vars);
	ft_printf("Program terminated\n");
	exit(status);
}

void	display_info(int status)
{
	if (status == 0)
	{
		ft_printf("*****         GLOBAL         *****\n\n");
		ft_printf("   a   => decrement definition\n");
		ft_printf("   s   => Increment definition\n\n");
		ft_printf("*****       Mandatory        *****\n\n");
		ft_printf("Input error, available commands:\n");
		ft_printf("./fract-ol Mandelbrot\n");
		ft_printf("./fract-ol Julia float-x floaty-y\n\n\n");
		ft_printf("*****       	Bonus        *****\n\n");
		ft_printf("./fract-ol-bonus BS\n");
		ft_printf("./fract-ol-bonus Dragon\n");
		ft_printf("   c   => change colors randomly\n");
		ft_printf("   r   => change main color to red\n");
		ft_printf("   g   => change main color to green\n");
		ft_printf("   b   => change main color to blue\n");
		ft_printf("arrows => to move view change view\n");
	}
	else if (status == 1)
		ft_putstr_fd("*** malloc faild !***\n", 2);
}

void	fexit_data(t_vars *vars)
{
	display_info(1);
	if (!vars)
		exit(1);
	if (!vars->img_data)
	{
		free(vars);
		exit(1);
	}
	if (!vars->frctl)
	{
		free(vars->img_data);
		free(vars);
		exit(1);
	}
}

double	get_module(double x, double y)
{
	return (sqrt(pow(x, 2) + pow(y, 2)));
}

int	is_double(char *number)
{
	if (!(*number))
		return (0);
	if (*number == '-')
		number++;
	while (*number && *number != '.')
	{
		if (!ft_isdigit(*number))
			return (0);
		number++;
	}
	if (!*number)
		return (1);
	if (*number != '.')
		return (0);
	number++;
	if (!(*number))
		return (0);
	while (*number)
	{
		if (!ft_isdigit(*number))
			return (0);
		number++;
	}
	return (1);
}
