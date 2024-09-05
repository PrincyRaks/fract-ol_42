#include "fractol.h"

int main(void)
{
    void    *mlx;
    void    *frame;

    mlx = mlx_init();
    frame = mlx_new_window(mlx, 500, 500, "Frame");
    mlx_loop(mlx);
    return (0);
}