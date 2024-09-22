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

static void draw_line(void *mlx_ptr, void *win_ptr, t_point p1, t_point p2) {
    mlx_pixel_put(mlx_ptr, win_ptr, (int)p1.x, (int)p1.y, 0xFFFFFF);
    mlx_pixel_put(mlx_ptr, win_ptr, (int)p2.x, (int)p2.y, 0xFFFFFF);
}

void	draw_snowflake(t_frame *frame)
{
	int	height;
	int width;
	int x_start;

	height = WIN_HEIGHT - WIN_HEIGHT / 4;
	width = WIN_WIDTH;
	x_start = width / 2 - height / 2;
	koch_segment(frame, (t_point){x_start + 20, height - 20}, (t_point){x_start + height - 20, height - 20}, 10);
	koch_segment(frame,(t_point){x_start + height - 20, height - 20}, (t_point){x_start + height / 2, 20}, 10);
	koch_segment(frame, (t_point){x_start + height / 2, 20}, (t_point){x_start + 20, height - 20}, 10);
}

void	koch_segment(t_frame *frame, t_point p1, t_point p2, int i)
{
	t_point pA;
	t_point pB;
	t_point pC;

	if (i == 0)
		draw_line(frame->mlx, frame->mlx_win, p1, p2);
	else
	{
		pA.x = p1.x + (p2.x - p1.x) / 3;
		pA.y = p1.y + (p2.y - p1.y) / 3;
		// pB.x = (int)(0.5 * (p1.x + p2.x) + sqrt(3) * (p2.y - p1.y) / 6);
		// pB.y = (int)(0.5 * (p1.y + p2.y) + sqrt(3) * (p1.x - p2.x) / 6);
		pC.x = p1.x + 2 * (p2.x - p1.x) / 3;
		pC.y = p1.y + 2 * (p2.y - p1.y) / 3;
		pB.x = pA.x + (pC.x - pA.x) * cos(M_PI / 3) - (pC.y - pA.y) * sin(M_PI / 3);
		pB.y = pA.y + (pC.x - pA.x) * sin(M_PI / 3) + (pC.y - pA.y) * cos(M_PI / 3);
		koch_segment(frame, p1, pA, i - 1);
		koch_segment(frame, pA, pB, i - 1);
		koch_segment(frame, pB, pC, i - 1);
		koch_segment(frame, pC, p2, i - 1);
	}
	
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
			else if (!ft_strncmp(frame->name, "snowflake", 9))
				draw_snowflake(frame);
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