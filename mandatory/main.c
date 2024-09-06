#include "fractol.h"

void	put_pixel(t_data *data, t_point point, int color)
{
	char	*dst;

	if ((point.x >= 0 && point.x <= WINDOW_WIDTH) && (point.y >= 0
			&& point.y <= WINDOW_HEIGHT))
	{
		dst = data->addr + (point.y + data->line_length + point.x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_rectangle(t_data *image, t_point point, int width, int height)
{
	int	x_end;
	int	y_end;
	int	color;

	x_end = point.x + width;
	y_end = point.y + height;
	color = 0x00FFABCC;
	while (point.x <= x_end && point.y <= y_end)
	{
		put_pixel(image, point, color);
		point.x++;
		point.y++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*frame;
	t_data	image;
	t_point	point;

	mlx = mlx_init();
	if (!mlx)
		perror("Error for initializing mlx");
	frame = mlx_new_window(mlx, 400, 400, "Frame");
	image.img = mlx_new_image(mlx, 400, 500);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	point.x = 1;
	point.y = 1;
	draw_rectangle(&image, point, 50, 50);
	mlx_put_image_to_window(mlx, frame, image.img, point.x, point.y);
	mlx_loop(mlx);
	return (0);
}
