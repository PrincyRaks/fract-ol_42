CFLAGS= -Wall -Werror -Wextra -g
MLX_FLAGS= -lXext -lX11 -lm

SRCS= 	./mandatory/main.c \
		./mandatory/check_arg.c \
		./mandatory/frame.c 

OBJS= $(SRCS:.c=.o)

NAME= fractol

LIBFT_A= ./libft/libft.a
MLX_A= ./minilibx/libmlx.a

all: libft mlx $(NAME)

$(OBJS):%.o:%.c $(MLX_A)
	cc $(CFLAGS) -I./minilibx -c $< -o $@

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) $(LIBFT_A) $(MLX_A) $(MLX_FLAGS) -o $(NAME)

libft:
	make -C ./libft

mlx:
	make -C ./minilibx

clean:
	rm -f $(OBJS)
	make clean -C ./minilibx
	make clean -C ./libft 

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_A)
	rm -f $(MLX_A)

re: fclean all

.PHONY: clean fclean re libft mlx all