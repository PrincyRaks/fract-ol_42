/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:49:43 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/18 16:20:24 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_image(t_frame *frame)
{
	if (!frame)
		return ;
	frame->img.img_ptr = mlx_new_image(frame->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (frame->img.img_ptr == NULL)
	{
		mlx_destroy_window(frame->mlx, frame->mlx_win);
		mlx_destroy_display(frame->mlx);
		free(frame->mlx);
		print_error("Error to initialize image\n");
	}
	frame->img.pixel_ptr = mlx_get_data_addr(frame->img.img_ptr,
			&frame->img.bits_per_pixel, &frame->img.line_length,
			&frame->img.endian);
}

static void	init_value(t_frame *frame, char *name)
{
	if (!frame)
		return ;
	frame->name = name;
	frame->max_iteration = 42;
	frame->move_x = 0.;
	frame->move_y = 0.;
	frame->r = 15;
	frame->g = 22;
	frame->b = 10;
	frame->zoom_in = 0.;
	frame->zoom_out = 0.;
}

void	init_frame(t_frame *frame, char *name)
{
	if (frame == NULL)
		print_error("Struct not initializing\n");
	frame->mlx = mlx_init();
	if (frame->mlx == NULL)
		print_error("Error to initialize mlx\n");
	frame->mlx_win = mlx_new_window(frame->mlx, WIN_WIDTH, WIN_HEIGHT, name);
	if (frame->mlx_win == NULL)
	{
		mlx_destroy_display(frame->mlx);
		free(frame->mlx);
		print_error("Error to initialize window\n");
	}
	init_image(frame);
	init_event(frame);
	init_value(frame, name);
}
