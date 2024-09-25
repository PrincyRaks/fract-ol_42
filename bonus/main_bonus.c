/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:05:15 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/25 16:24:10 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int argc, char **argv)
{
	t_frame	frame;

	frame.real = 0.;
	frame.imaginary = 0.;
	if ((argc == 2 && (!compare_str(argv[1], "mandelbrot", 10,
					ft_strlen(argv[1])) || !compare_str(argv[1], "multicorn", 9,
					ft_strlen(argv[1])))) || ((argc == 4
				&& !compare_str(argv[1], "julia", 5, ft_strlen(argv[1])))
			&& (is_doubledigit(argv[2]) && is_doubledigit(argv[3]))))
	{
		init_frame(&frame, argv[1]);
		init_color(&frame, 12, 9, 5);
		if (argc == 4)
		{
			frame.real = ft_atof(argv[2]);
			frame.imaginary = ft_atof(argv[3]);
			init_color(&frame, 2, 2, 5);
		}
		draw_fractal(&frame);
		mlx_loop(frame.mlx);
	}
	else
		print_error(ERROR_ARG);
	return (0);
}
