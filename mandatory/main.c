#include "fractol.h"

int	main(int argc, char **argv)
{
	t_frame	frame;

	frame.real = 0.;
	frame.imaginary = 0.;
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || ((argc == 4
				&& !ft_strncmp(argv[1], "julia", 5)) && (is_doubledigit(argv[2])
				&& is_doubledigit(argv[3]))))
	{
		init_frame(&frame, argv[1]);
		if (argc == 4)
		{
			frame.real = ft_atof(argv[2]);
			frame.imaginary = ft_atof(argv[3]);
			draw_fractal(&frame);
		}
		else
			draw_fractal(&frame);
		mlx_loop(frame.mlx);
	}
	else
		print_error(ERROR_ARG);
	return (0);
}
