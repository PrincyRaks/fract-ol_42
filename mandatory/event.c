/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:14:02 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/17 16:39:23 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void close_window(t_frame *frame)
{
    mlx_destroy_image(frame->mlx, frame->img.img_ptr);
    mlx_destroy_window(frame->mlx,frame->mlx_win);
    mlx_destroy_display(frame->mlx);
    free(frame->mlx);
    exit(0);
}

static int  key_handler(int keycode, t_frame *frame)
{
    if (keycode == XK_Escape)
        close_window(frame);
    else if ();
    return (0);
}

static int  mouse_handler(int button, int x, int y, void *frame)
{
    (void)frame;
    printf("button: %d et X; %d Y: %d \n", button, x, y);
    return (0);
}

void    init_event(t_frame *frame)
{
    // mlx_mouse_hook(frame->mlx_win, mouse_handler, frame);
    mlx_key_hook(frame->mlx_win, key_handler, frame);
    // mlx_hook(frame->mlx_win, MotionNotify, PointerMotionMask, mouse_handler, frame);
    mlx_hook(frame->mlx_win, ButtonPress, ButtonPressMask, mouse_handler, frame);
    // mlx_hook(frame->mlx_win, DestroyNotify, StructureNotifyMask, close_window, frame);
}
