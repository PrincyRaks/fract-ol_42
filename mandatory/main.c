/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:43:02 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/20 10:43:39 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_frame	frame;

	frame.real = 0.;
	frame.imaginary = 0.;
	if ((argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10)
				|| !ft_strncmp(argv[1], "snowflake", 9))) || ((argc == 4
				&& !ft_strncmp(argv[1], "julia", 5)) && (is_doubledigit(argv[2])
				&& is_doubledigit(argv[3]))))
	{
		init_frame(&frame, argv[1]);
		init_color(&frame, 15, 22, 10);
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
