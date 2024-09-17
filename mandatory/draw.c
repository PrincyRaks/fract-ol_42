/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:06:11 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/17 16:12:18 by rrakotos         ###   ########.fr       */
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
	c.x = scale(frame->x_win, 2, -2, 0, WIN_WIDTH);
	c.y = scale(frame->y_win, -2, 2, 0, WIN_HEIGHT);
	while (i < MAX_ITER && ((z.x * z.x) + (z.y * z.y)) < 4.)
	{
		tmp_x = ((z.x * z.x) - (z.y * z.y)) + c.x;
		z.y = (2. * z.x * z.y) + c.y;
		z.x = tmp_x;
		i++;
	}
	if (i == MAX_ITER)
		ft_putpixel(&frame->img, frame->x_win, frame->y_win, BLACK);
	else
		ft_putpixel(&frame->img, frame->x_win, frame->y_win, get_color(smooth_color(i, z)));
}

void    draw_julia(double real, double imaginary, t_frame *frame)
{
    t_point	z;
	t_point	c;
	int		i;
	double	tmp_x;

	i = 0;
	// frame->new_max = -2;
	// frame->new_min = 2;
	z.x = scale(frame->x_win, 2, -2, 0, WIN_WIDTH);
	z.y = scale(frame->y_win, -2, 2, 0, WIN_HEIGHT);
	c.x = real;
	c.y = imaginary;
	while (i < MAX_ITER && ((z.x * z.x) + (z.y * z.y)) < 4.)
	{
		tmp_x = ((z.x * z.x) - (z.y * z.y)) + c.x;
		z.y = (2. * z.x * z.y) + c.y;
		z.x = tmp_x;
		i++;
	}
	if (i == MAX_ITER)
		ft_putpixel(&frame->img, frame->x_win, frame->y_win, BLACK);
	else
		ft_putpixel(&frame->img, frame->x_win, frame->y_win, get_color(smooth_color(i, z)));
}
