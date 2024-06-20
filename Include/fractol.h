/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:13:49 by pierre            #+#    #+#             */
/*   Updated: 2024/06/20 11:45:01 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define ESC 65307
# define ON_MOUSEMOVE 6
#include <math.h>
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	*img_data;
	int		win_x;
	int		win_y;
}	t_vars;

/* typedef struct	s_us {
	int	keycode;
	void	*mlx;
}	t_us;
 */
/* main */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_windows(int keycode, t_vars *params);
int		mousemoves(int button, int x, int y, void *params);
int		close_page(void *params);
void	set_bckclr(t_data *data, int dimx, int dimy, int color);
t_vars	*init_vars(int	size_x, int	size_y, char	*win_name);
void	set_hooks(t_vars *data);

void pixel_setter(t_vars *data);
void	mandelbrot(t_vars *data, double x, double y, double precision);
int	get_nextfract(double cx, double cy, int iteration);
double	get_module(double x, double y);

/* colors_bitshift */
int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);
int	add_shade(float shade, int color);
int	invert(int	color);

#endif
