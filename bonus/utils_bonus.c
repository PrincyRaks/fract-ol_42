/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:59:05 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/25 11:06:02 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	compare_str(const char *s1, const char *s2, size_t n2, size_t n1)
{
	size_t	i;

	i = 0;
	if (n2 != n1)
		return (n2 - n1);
	while (i < n2 && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

double	scale(double unscaled, double new_max, double new_min, double old_max)
{
	return ((new_max - new_min) * (unscaled - 0) / (old_max - 0) + new_min);
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

void	free_tab(char **str, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		free(str[i]);
	free(str);
}
