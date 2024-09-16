#include "fractol.h"

int	main(int argc, char **argv)
{
	t_frame	frame;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandlebrot", 10)) || ((argc == 4
				&& !ft_strncmp(argv[1], "julia", 5)) && (is_doubledigit(argv[2])
				&& is_doubledigit(argv[3]))))
	{
		init_frame(&frame, argv[1]);
		if (argc == 4)
			draw_fractal(ft_atof(argv[2]), ft_atof(argv[3]), &frame);
		else
			draw_fractal(0., 0., &frame);
		mlx_loop(frame.mlx);
	}
	else
		print_error(ERROR_ARG);
	return (0);
}
