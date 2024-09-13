/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakotos <rrakotos@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:44:58 by rrakotos          #+#    #+#             */
/*   Updated: 2024/09/13 17:13:01 by rrakotos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_ARG "Please enter: \n\t\"./fractol mandlebrot\" or \n\t\"./fractol julia <number_1> <number_2>\" \n"
# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define MAX_ITER 50

# define PSYCHEDELIC_PURPLE 0x9C00FF
# define PSYCHEDELIC_YELLOW 0xFFFF00
# define PSYCHEDELIC_GREEN 0x00FF00
# define PSYCHEDELIC_RED 0xFF0000
# define PSYCHEDELIC_CYAN 0x00FFFF
# define PSYCHEDELIC_ORANGE 0xFFA500
# define PSYCHEDELIC_PINK 0xFF00FF
# define PSYCHEDELIC_BLUE 0x0000FF

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;
typedef struct s_frame
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	char	*name;
}			t_frame;
typedef struct s_point
{
	double	x;
	double	y;
}			t_point;
void		print_error(char *s);
void		init_frame(t_frame *frame, char *name);
#endif