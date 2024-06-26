/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:12:24 by pierre            #+#    #+#             */
/*   Updated: 2024/06/25 22:44:37 by pierre           ###   ########.fr       */
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
		ft_printf("Input error, available commands:\n");
		ft_printf("./fractol Mandelbrot\n");
		ft_printf("./fractol Julia float-x floaty-y\n");
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

void	flip(char *str)
{
	int	strlen;
	int	i;
	char	temp;
	if (!str)
		return ;
	if (!ft_strcmp(str, ""))
		return ;
	strlen = ft_strlen(str);
	i = 0;
	while (i < strlen / 2)
	{
		temp = str[i];
		str[i] = str[strlen - 1];
		str[strlen - 1] = temp;
		i++;
	}	
}
