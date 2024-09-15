#include "fractol.h"

int	main(int argc, char **argv)
{
	t_frame	frame;
	
	if ((argc == 2 && !ft_strncmp(argv[1], "mandlebrot", 10)) 
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		init_frame(&frame, argv[1]);
		draw_fractal(&frame);
		mlx_loop(frame.mlx);
	}
	else
		print_error(ERROR_ARG);
	return (0);
}
