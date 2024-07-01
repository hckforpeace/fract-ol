/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:13:49 by pierre            #+#    #+#             */
/*   Updated: 2024/06/30 23:11:52 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# ifndef WIDTH
#  define WIDTH 1920
# endif

# ifndef HEIGHT
#  define HEIGHT 1080
# endif

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "libft.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fractal
{
	double	x;
	double	y;
	double	cx;
	double	cy;
}	t_fractal;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		*img_data;
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
	int			xorg;
	int			yorg;
	int			zoom_times;
}	t_vars;

/* main and main_bonus */
int		jober(char	*frctl, double x, double y);
t_vars	*init_vars(int size_x, int size_y, char *win_name, char *frct);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/* hooks.c and hooks_bonus.c */
int		key_events(int keycode, t_vars *params);
int		mousemoves(int button, int x, int y, t_vars *params);
int		close_wincross(void *params);
void	set_hooks(t_vars *data);
void	dragon_curve(t_vars *data);

/* utils.c */
void	display_info(int status);
void	free_vars(t_vars *vars, int status);
void	fexit_data(t_vars *vars);
double	get_module(double x, double y);
int		is_double(char *number);

/* fractol.c fractol_bonus.c */
int		setbase(t_vars *data, double x, double y);
int		getnextfract(t_vars *data, int	*loops);
int		julia(t_vars *data, int	*loops);
int		mandelbrot(t_vars *data, int *loops);
int		burning_ship(t_vars *data, int *loops);

/* colors_bitshift */
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		invert(int color);

/* display_action.c */
void	apply_action(t_vars *vars, int keycode);
void	zoom_in_mouse(double offsetx, double offsety, t_vars *params);

/* dragoncrv.c */
char	drawline(t_vars *data, int x, int y, char c);
void	ft_swap(char *str);
void	ft_strrplc(char *str);
char	*get_dragon(int i, char *str);
char	display_case(char previous, char instruction, t_vars *data);

/* pixels.c */
int		pixel_setter(t_vars *data);
int		create_trgb(int t, int r, int g, int b);
int		add_shade(float shade, int color);
int		get_offsetx(int x, double xb, t_vars *params);
int		get_offsety(int y, double yb, t_vars *params);

#endif
