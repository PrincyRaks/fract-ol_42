/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:06:11 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/20 17:18:34 by rrakotos         ###   ########.fr       */
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
	c.x = scale(frame->x_win, 2, -2, WIN_WIDTH) * frame->zoom
		+ frame->move_x;
	c.y = scale(frame->y_win, -2, 2, WIN_HEIGHT) * frame->zoom
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
	z.x = scale(frame->x_win, 2, -2, WIN_WIDTH) * frame->zoom
		+ frame->move_x;
	z.y = scale(frame->y_win, -2, 2, WIN_HEIGHT) * frame->zoom
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

// void	koch_segment(){}

// void	draw_snowflake(t_frame *frame)
// {
// 	t_point p1;
// 	t_point p2;
// 	t_point p3;

// 	p1.x = WIN_WIDTH / 2;
// 	p1.y = 100;
// 	p2.x = 200;
// 	p2.y = 500;
// 	p3.x = 600;
// 	p3.y = 500;
// }

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
			else if (!ft_strncmp(frame->name, "snowflake", 9))
				draw_snowflake();
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