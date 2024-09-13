/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:59:05 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/13 17:18:52 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scale(double unscaled_num, double new_min, double new_max,
		double old_len)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / old_len + new_min);
}

void	ft_putpixel(t_frame *frame, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		pixel = frame->img.img_ptr + (y * frame->img.line_length + x
				* (frame->img.bits_per_pixel / 8));
		*(unsigned int)pixel = color;
	}
}

void	draw_fractal(t_frame *frame, double real, double imaginary, char *name)
{
	int	x_win;
	int	y_win;

	x_win = 0;
	y_win = 0;
	while (x_win < WIN_WIDTH)
	{
		y_win = 0;
		while (y_win < WIN_HEIGHT)
		{
            draw_mandlebrot(x, y, frame);
			// if (frame->name == "mandlebrot")
			// 	// function mandlebrot
			// 	// else if (frame->name == "julia")
			// 	// function julia
			// 	// else if () bonus 1
			// 	y_win++;
		}
		x_win++;
	}
    mlx_put_image_to_window(frame->mlx, frame->mlx_win, frame->img, 0 , 0);
}

void	draw_mandlebrot(int x, int y, t_frame *frame)
{
	t_point	z;
	t_point	c;
	int		i;
    double  tmp_x;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = scale(x, -2, 2, WIN_WIDTH);
	c.y = scale(y, -2, 2, WIN_HEIGHT);
	while (i < MAX_ITER && (pow(z.x, 2) + pow(z.y, 2)) < 4.)
	{
        tmp_x = (z.x * z.x) - (z.y * z.y) + c.x;
        z.y = (2. * z.x * z.y) + c.y;
        z.x = tmp_x;
        i++;
	}
    if (i == MAX_ITER)
        ft_putpixel(frame, x, y, 0x000000);
    else
        ft_putpixel(frame, x, y, PSYCHEDELIC_YELLOW * (i * 255));
}

// void	draw_julia(void)
// {
// }