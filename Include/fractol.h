/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:13:49 by pierre            #+#    #+#             */
/*   Updated: 2024/06/26 01:27:37 by pierre           ###   ########.fr       */
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
#include <X11/keysym.h>
#include <X11/X.h>
#include "libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_fractal {
	double	x;
	double	y;
	double	cx;
	double	cy;
}	t_fractal;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	*img_data;
	double		win_x;
	double		win_y;
	t_fractal	*frctl;
	char		*frc_name;
	int			precision;
	int			moveviewx;
	int			moveviewy;
	double		scale;
	int			color;
	int			dragx;
	int			dragy;
}	t_vars;



typedef	struct s_tend 
{
	int 	diverges;
	float	behaviour;
	int	cx;
	int	cy;
}	t_tend;

void	display_info(int status);
int		jober(char	*frctl, double x, double y);

/* main */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_events(int keycode, t_vars *params);
int		mousemoves(int button, int x, int y, t_vars *params);
int		close_wincross(void *params);
void	set_bckclr(t_data *data, int dimx, int dimy, int color);
t_vars	*init_vars(int size_x, int size_y, char *win_name, char *frct);
void	set_hooks(t_vars *data);

int	julia(t_vars *data, int	*loops);

int	pixel_setter(t_vars *data);
int	setbase(t_vars *data, double x, double y);
int	mandelbrot(t_vars *data, int *loops);
double	get_module(double x, double y);
void	free_vars(t_vars *vars, int status);
int	getnextfract(t_vars *data, int	*loops);

/* colors_bitshift */
int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);
int	add_shade(float shade, int color);
int	invert(int	color);
int	create_trgb(int t, int r, int g, int b);

void	fexit_data(t_vars *vars);

//zoom

void	apply_action(t_vars *vars, int	keycode);

// dragon curve

char	drawline(t_vars *data, int x, int y, char c);
void	ft_swap(char *str);
void	ft_strrplc(char *str);
char	*get_dragon(int i, char *str);
void	dragon_curve(t_vars *data);


#endif
