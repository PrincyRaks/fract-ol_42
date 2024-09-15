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

static double	scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
}

static void	ft_putpixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if ((x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT) && (img != NULL && img->img_ptr != NULL))
	{
		pixel = img->img_ptr + (y * img->line_length + x
				* (img->bits_per_pixel / 8));
		*(unsigned int*)pixel = color;
	}
}

static void	draw_mandlebrot(int x, int y, t_frame *frame)
{
	t_point	z;
	t_point	c;
	int		i;
    double	tmp_x;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = scale(x, -2, 2, 0, WIN_WIDTH);
	c.y = scale(y, 2, -2, 0, WIN_HEIGHT);
	while (i < MAX_ITER && ((z.x * z.x) + (z.y *z.y)) < 4.)
	{
        tmp_x = ((z.x * z.x) - (z.y * z.y)) + c.x;
        z.y = (2. * z.x * z.y) + c.y;
        z.x = tmp_x;
        i++;
	}
    if (i == MAX_ITER)
		ft_putpixel(&frame->img, x, y, 0x000000);
    else
        ft_putpixel(&frame->img, x, y, 0xFCBE11 * i);
}

void	draw_fractal(t_frame *frame)
{
	int	x_win;
	int	y_win;

	x_win = 0;
	while (x_win <  WIN_WIDTH)
	{
		y_win = 0;
		while (y_win < WIN_HEIGHT)
		{
            draw_mandlebrot(x_win, y_win, frame);
			// if (frame->name == "mandlebrot")
				// function mandlebrot
			// else if (frame->name == "julia")
				// function julia
			// else if () bonus 1
			y_win++;
		}
		x_win++;
	}
    mlx_put_image_to_window(frame->mlx, frame->mlx_win, frame->img.img_ptr, 0, 0);
}

// void	draw_julia(void)
// {
// }