/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_others.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:12:58 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/25 17:12:59 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	draw_multicorne(t_frame *frame)
// {
// 	t_point	z;
// 	t_point	c;
// 	int		i;
// 	double	tmp_x;

// 	i = 0;
// 	z.x = 0.0;
// 	z.y = 0.0;
// 	c.x = scale(frame->x_win, 2, -2, WIN_WIDTH) * frame->zoom + frame->move_x;
// 	c.y = scale(frame->y_win, -2, 2, WIN_HEIGHT) * frame->zoom + frame->move_y;
// 	while (i < frame->max_iteration && ((z.x * z.x) + (z.y * z.y)) < 4.)
// 	{
// 		tmp_x = (pow(z.x, 3) -(3. * z.x * pow(z.y, 2)))  + c.x;
// 		z.y = (-3. * pow(z.x, 2) * z.y + pow(z.y, 3)) + c.y;
// 		z.x = tmp_x;
// 		i++;
// 	}
// 	if (i == frame->max_iteration)
// 		ft_putpixel(&frame->img, frame->x_win, frame->y_win, BLACK);
// 	else
// 		ft_putpixel(&frame->img, frame->x_win, frame->y_win, get_color(i, z,
// 				frame));
// }

// void	koch_revsegment(t_frame *frame, t_point p1, t_point p2, int i)
// {
// 	t_point pA;
// 	t_point pB;
// 	t_point pC;

// 	if (i == 0)
// 	{
// 		ft_putpixel(&frame->img, (int)p1.x, (int)p1.y, WHITE);
// 		ft_putpixel(&frame->img, (int)p2.x, (int)p2.y, WHITE);
// 	}
// 	else
// 	{
// 		pA.x = p1.x + (p2.x - p1.x) / 3;
// 		pA.y = p1.y + (p2.y - p1.y) / 3;
// 		pB.x = (int)(0.5 * (p1.x + p2.x) + sqrt(3) * (p2.y - p1.y) / 6);
// 		pB.y = (int)(0.5 * (p1.y + p2.y) + sqrt(3) * (p1.x - p2.x) / 6);
// 		pC.x = p1.x + 2 * (p2.x - p1.x) / 3;
// 		pC.y = p1.y + 2 * (p2.y - p1.y) / 3;
// 		koch_segment(frame, p1, pA, i - 1);
// 		koch_segment(frame, pA, pB, i - 1);
// 		koch_segment(frame, pB, pC, i - 1);
// 		koch_segment(frame, pC, p2, i - 1);
// 	}

// }

// void	draw_snowflake(t_frame *frame)
// {
// 	int	height;
// 	int	width;
// 	int	x_start;

// 	height = WIN_HEIGHT - WIN_HEIGHT / 4;
// 	width = WIN_WIDTH;
// 	x_start = width / 2 - height / 2;
// 	koch_segment(frame, (t_point){x_start + 20, height - 20}, (t_point){x_start
// 		+ height - 20, height - 20}, 10);
// 	koch_segment(frame, (t_point){x_start + height - 20, height - 20},
// 		(t_point){x_start + height / 2, 20}, 10);
// 	koch_segment(frame, (t_point){x_start + height / 2, 20}, (t_point){x_start
// 		+ 20, height - 20}, 10);
// 	mlx_put_image_to_window(frame->mlx, frame->mlx_win, frame->img.img_ptr, 0,
// 		0);
// }

// void	koch_segment(t_frame *frame, t_point p1, t_point p2, int i)
// {
// 	t_point	pA;
// 	t_point	pB;
// 	t_point	pC;

// 	if (i == 0)
// 	{
// 		ft_putpixel(&frame->img, (int)p1.x, (int)p1.y, WHITE);
// 		ft_putpixel(&frame->img, (int)p2.x, (int)p2.y, WHITE);
// 	}
// 	else
// 	{
// 		pA.x = p1.x + (p2.x - p1.x) / 3;
// 		pA.y = p1.y + (p2.y - p1.y) / 3;
// 		pC.x = p1.x + 2 * (p2.x - p1.x) / 3;
// 		pC.y = p1.y + 2 * (p2.y - p1.y) / 3;
// 		pB.x = pA.x + (pC.x - pA.x) * cos(PI / 3) - (pC.y - pA.y) * sin(PI / 3);
// 		pB.y = pA.y + (pC.x - pA.x) * sin(PI / 3) + (pC.y - pA.y) * cos(PI / 3);
// 		koch_segment(frame, p1, pA, i - 1);
// 		koch_segment(frame, pA, pB, i - 1);
// 		koch_segment(frame, pB, pC, i - 1);
// 		koch_segment(frame, pC, p2, i - 1);
// 	}
// }
