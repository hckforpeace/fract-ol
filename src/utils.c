/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:12:24 by pierre            #+#    #+#             */
/*   Updated: 2024/06/22 15:33:28 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_vars(t_vars *vars)
{
	free(vars->frctl);
	free(vars->img_data);
	free(vars);
}

void display_info(int status, t_vars *vars)
{
	if (status == 0)
	{
		ft_printf("Input error, available commands:\n");
		ft_printf("./fractol Mandelbrot\n");
		ft_printf("./fractol Julia floatx floaty");
	}
	else if(status == 1)
	{
		free_vars(vars);
		ft_putstr_fd("*** malloc faild !***\n", 2);
	}
	exit(1);
}