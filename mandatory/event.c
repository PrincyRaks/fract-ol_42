/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:14:02 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/18 16:20:39 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	close_window(t_frame *frame)
{
	mlx_destroy_image(frame->mlx, frame->img.img_ptr);
	mlx_destroy_window(frame->mlx, frame->mlx_win);
	mlx_destroy_display(frame->mlx);
	free(frame->mlx);
	exit(0);
	return (0);
}

static int	key_handler(int keycode, t_frame *frame)
{
	if (keycode == XK_Escape)
		close_window(frame);
	else if (keycode == XK_Left)
		frame->move_x += 0.1;
	else if (keycode == XK_Right)
		frame->move_x -= 0.1;
	else if (keycode == XK_Up)
		frame->move_y -= 0.1;
	else if (keycode == XK_Down)
		frame->move_y += 0.1;
	else if (keycode == 65451)
		frame->max_iteration += 10;
	else if (keycode == 65453)
		frame->max_iteration -= 10;
	else if (keycode == 114)
		frame->r += 10;
	else if (keycode == 103)
		frame->g += 10;
	else if (keycode == 98)
		frame->b += 10;
	draw_fractal(frame);
	return (0);
}

// static int  mouse_handler(int button, int x, int y, void *frame)
// {
// 	// in
// 	if (button == Button5)
// 	// out
// 	else if (button == Button4)
	
//     return (0);
// }

// static int motion_handler(int button, int x, int y, t_frame *frame)
// {
//     (void)button;
//     frame->x_win = x;
//     frame->y_win = y;
// 	// if fractale is julia make motion 
//     return (0);
// }

void	init_event(t_frame *frame)
{
	// mlx_mouse_hook(frame->mlx_win, mouse_handler, frame);
	mlx_key_hook(frame->mlx_win, key_handler, frame);
	// mlx_hook(frame->mlx_win, MotionNotify, PointerMotionMask, motion_handler,frame);
	mlx_hook(frame->mlx_win, KeyRelease, KeyReleaseMask, key_handler,frame);
	mlx_hook(frame->mlx_win, DestroyNotify, StructureNotifyMask, close_window, frame);
}
