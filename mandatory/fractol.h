/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:44:58 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/19 15:24:47 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_ARG "Please enter: \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <number_1> <number_2>\" \n"
# define WIN_WIDTH 800
# define WIN_HEIGHT 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define PURPLE 0x9C00FF
# define ORANGE 0xFFA500
# define BLUE 0x0000FF

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;
typedef struct s_point
{
	double	x;
	double	y;
}			t_point;
typedef struct s_frame
{
	void	*mlx;
	void	*mlx_win;

	t_img	img;
	int		max_iteration;
	char	*name;
	int		x_win;
	int		y_win;
	double	real;
	double	imaginary;
	double	move_x;
	double	move_y;
	int		r;
	int		g;
	int		b;
	double	scale_min;
	double	scale_max;
	double	zoom;
}			t_frame;
void		print_error(char *s);
void		init_frame(t_frame *frame, char *name);
void		draw_fractal(t_frame *frame);
void		draw_mandelbrot(t_frame *frame);
void		ft_putpixel(t_img *img, int x, int y, int color);
// double		scale(double unscaled, t_frame *frame, double old_min,
// 				double old_max);
double		scale(double unscaled, double new_max, double new_min,
				double old_min, double old_max);
void		draw_julia(double x, double y, t_frame *frame);
int			is_doubledigit(char *str);
double		ft_atof(char *str);
int			get_color(int i, t_point z, t_frame *frame);
void		init_event(t_frame *frame);
void		repaint(t_frame *frame);
void		init_image(t_frame *frame);
void		init_color(t_frame *frame, int r, int g, int b);
#endif