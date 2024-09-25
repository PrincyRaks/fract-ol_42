/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:05:18 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/25 16:23:27 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	draw_mandelbrot(t_frame *frame)
{
	t_point	z;
	t_point	c;
	int		i;
	double	tmp_x;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = scale(frame->x_win, 2, -2, WIN_WIDTH) * frame->zoom + frame->move_x;
	c.y = scale(frame->y_win, -2, 2, WIN_HEIGHT) * frame->zoom + frame->move_y;
	while (i < frame->max_iteration && ((z.x * z.x) + (z.y * z.y)) < 4.)
	{
		tmp_x = ((z.x * z.x) - (z.y * z.y)) + c.x;
		z.y = (2. * z.x * z.y) + c.y;
		z.x = tmp_x;
		i++;
	}
	if (i == frame->max_iteration)
		ft_putpixel(&frame->img, frame->x_win, frame->y_win, BLACK);
	else
		ft_putpixel(&frame->img, frame->x_win, frame->y_win, get_color(i, z,
				frame));
}

static void	draw_julia(double real, double imaginary, t_frame *frame)
{
	t_point	z;
	t_point	c;
	int		i;
	double	tmp_x;

	i = 0;
	z.x = scale(frame->x_win, 2, -2, WIN_WIDTH) * frame->zoom + frame->move_x;
	z.y = scale(frame->y_win, -2, 2, WIN_HEIGHT) * frame->zoom + frame->move_y;
	c.x = real;
	c.y = imaginary;
	while (i < frame->max_iteration && ((z.x * z.x) + (z.y * z.y)) < 4.)
	{
		tmp_x = ((z.x * z.x) - (z.y * z.y)) + c.x;
		z.y = (2. * z.x * z.y) + c.y;
		z.x = tmp_x;
		i++;
	}
	if (i == frame->max_iteration)
		ft_putpixel(&frame->img, frame->x_win, frame->y_win, WHITE);
	else
		ft_putpixel(&frame->img, frame->x_win, frame->y_win, get_color(i, z,
				frame));
}

void	draw_multicorn(t_frame *frame)
{
	t_point	z;
	t_point	c;
	int		i;
	double	tmp_x;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = scale(frame->x_win, 2, -2, WIN_WIDTH) * frame->zoom + frame->move_x;
	c.y = scale(frame->y_win, -2, 2, WIN_HEIGHT) * frame->zoom + frame->move_y;
	while (i < frame->max_iteration && ((z.x * z.x) + (z.y * z.y)) < 4.)
	{
		tmp_x = (pow(z.x, 3) - (3. * z.x * pow(z.y, 2))) + c.x;
		z.y = (-3. * pow(z.x, 2) * z.y + pow(z.y, 3)) + c.y;
		z.x = tmp_x;
		i++;
	}
	if (i == frame->max_iteration)
		ft_putpixel(&frame->img, frame->x_win, frame->y_win, BLACK);
	else
		ft_putpixel(&frame->img, frame->x_win, frame->y_win, get_color(i, z,
				frame));
}

void	draw_fractal(t_frame *frame)
{
	frame->x_win = 0;
	while (frame->x_win < WIN_WIDTH)
	{
		frame->y_win = 0;
		while (frame->y_win < WIN_HEIGHT)
		{
			if (!ft_strncmp(frame->name, "mandelbrot", ft_strlen(frame->name)))
				draw_mandelbrot(frame);
			else if (!ft_strncmp(frame->name, "julia", ft_strlen(frame->name)))
				draw_julia(frame->real, frame->imaginary, frame);
			else if (!ft_strncmp(frame->name, "multicorn",
					ft_strlen(frame->name)))
				draw_multicorn(frame);
			frame->y_win++;
		}
		frame->x_win++;
	}
	mlx_put_image_to_window(frame->mlx, frame->mlx_win, frame->img.img_ptr, 0,
		0);
}

void	repaint(t_frame *frame)
{
	if (!frame)
		return ;
	mlx_destroy_image(frame->mlx, frame->img.img_ptr);
	init_image(frame);
	draw_fractal(frame);
}
