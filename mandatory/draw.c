/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:06:11 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/19 16:22:10 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_frame *frame)
{
	t_point	z;
	t_point	c;
	int		i;
	double	tmp_x;

	i = 0;
	// frame->new_max = -2;
	// frame->new_min = 2;
	z.x = 0.0;
	z.y = 0.0;
	c.x = scale(frame->x_win, 2, -2, 0, WIN_WIDTH) * frame->zoom
		+ frame->move_x;
	c.y = scale(frame->y_win, -2, 2, 0, WIN_HEIGHT) * frame->zoom
		+ frame->move_y;
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

void	draw_julia(double real, double imaginary, t_frame *frame)
{
	t_point	z;
	t_point	c;
	int		i;
	double	tmp_x;

	i = 0;
	// frame->new_max = -2;
	// frame->new_min = 2;
	z.x = scale(frame->x_win, 2, -2, 0, WIN_WIDTH) * frame->zoom
		+ frame->move_x;
	z.y = scale(frame->y_win, -2, 2, 0, WIN_HEIGHT) * frame->zoom
		+ frame->move_y;
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

void	draw_fractal(t_frame *frame)
{
	frame->x_win = 0;
	while (frame->x_win < WIN_WIDTH)
	{
		frame->y_win = 0;
		while (frame->y_win < WIN_HEIGHT)
		{
			if (!ft_strncmp(frame->name, "mandelbrot", 10))
				draw_mandelbrot(frame);
			else if (!ft_strncmp(frame->name, "julia", 5))
				draw_julia(frame->real, frame->imaginary, frame);
			// else if () bonus 1
			frame->y_win++;
		}
		frame->x_win++;
	}
	mlx_put_image_to_window(frame->mlx, frame->mlx_win, frame->img.img_ptr, 0,
		0);
}

void	draw_snowflake(){}