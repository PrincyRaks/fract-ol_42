#include "fractol.h"

int	main(int argc, char **argv)
{
	t_frame	frame;

	if ((argc >= 2 && argc <= 4) && (!ft_strncmp(argv[1], "julia", 5)
			|| !ft_strncmp(argv[1], "mandlebrot", 10)))
	{
        // if (argc == 3 || argc == 4)
        //     // check if the number is real
		init_frame(&frame, argv[1]);
	}
	else
		print_error(ERROR_ARG);
	return (0);
}
