/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:49:43 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/13 15:53:46 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_frame(t_frame *frame, char *name)
{
	frame->name = name;
	frame->mlx = mlx_init();
	if (frame->mlx == NULL)
		print_error("Error to initialize mlx");
	frame->mlx_win = mlx_new_window(frame->mlx, WIN_WIDTH, WIN_HEIGHT,
			frame->name);
	if (frame->mlx_win == NULL)
	{
		mlx_destroy_display(frame->mlx);
		free(frame->mlx);
		print_error("Error to initialize window");
	}
	frame->img.img_ptr = mlx_new_image(frame->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (frame->img.img_ptr == NULL)
	{
		mlx_destroy_window(frame->mlx,frame->mlx_win);
		// mlx_destroy_display(frame->mlx);
		free(frame->mlx);
		print_error("Error to initialize image");
	}
	frame->img.img_ptr = mlx_get_data_addr(frame->img.img_ptr,
			&frame->img.bits_per_pixel, &frame->img.line_length,
			&frame->img.endian);
}
