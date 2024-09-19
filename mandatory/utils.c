/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:59:05 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/19 15:24:07 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// double	scale(double unscaled, t_frame *frame, double old_min,
// double old_max)
// {
// 	return ((frame->new_max - frame->new_min) * (unscaled - old_min) / (old_max
// 			- old_min) + frame->new_min);
// }

double	scale(double unscaled, double new_max, double new_min, double old_min,
		double old_max)
{
	return ((new_max - new_min) * (unscaled - old_min) / (old_max - old_min)
		+ new_min);
}

void	ft_putpixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if ((x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT) && (img != NULL
			&& img->pixel_ptr != NULL))
	{
		pixel = img->pixel_ptr + (y * img->line_length + x
				* (img->bits_per_pixel / 8));
		*(unsigned int *)pixel = color;
	}
}

int	get_color(int i, t_point z, t_frame *frame)
{
	int		r;
	int		g;
	int		b;
	double	smooth;

	smooth = (i + 1) - log2(log((z.x * z.x + z.y * z.y)) / 2.);
	r = (int)(smooth * frame->r) % 256;
	g = (int)(smooth * frame->g) % 256;
	b = (int)(smooth * frame->b) % 256;
	return (r << 16 | g << 8 | b);
}

void	repaint(t_frame *frame)
{
	if (!frame)
		return ;
	mlx_destroy_image(frame->mlx, frame->img.img_ptr);
	init_image(frame);
	draw_fractal(frame);
}