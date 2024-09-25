/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:44:58 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/25 16:23:09 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_ARG \
	"\033[32mPlease enter:\033[30m \
	\n\t\033[35mreal:\033[30m decimal (eg: ±0.4) \
	\n\t\033[35mimaginary:\033[30m decimal (eg: ±0.4) \
	\n\t\033[34m\"./fractol_bonus mandelbrot\" \
	\n\t\"./fractol_bonus julia \033[35m<real> <imaginary>\033[34m\" \
	\n\t\"./fractol_bonus multicorn\"\n\033[30m"
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
int			compare_str(const char *s1, const char *s2, size_t n2, size_t n1);
int			is_doubledigit(char *str);
int			get_color(int i, t_point z, t_frame *frame);
void		init_frame(t_frame *frame, char *name);
void		init_event(t_frame *frame);
void		init_image(t_frame *frame);
void		init_color(t_frame *frame, int r, int g, int b);
double		scale(double unscaled, double new_max, double new_min,
				double old_max);
void		ft_putpixel(t_img *img, int x, int y, int color);
void		draw_fractal(t_frame *frame);
double		ft_atof(char *str);
void		repaint(t_frame *frame);
void		free_tab(char **str, int len);
#endif