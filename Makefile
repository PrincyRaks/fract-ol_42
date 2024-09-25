CFLAGS= -Wall -Werror -Wextra -o2
MLX_FLAGS= -lXext -lX11 -lm

SRCS= 	./mandatory/main.c \
		./mandatory/checkarg.c \
		./mandatory/init.c \
		./mandatory/utils.c \
		./mandatory/draw.c \
		./mandatory/event.c

SRC_BONUS=	./bonus/main_bonus.c \
			./bonus/draw_bonus.c \
			./bonus/event_bonus.c \
			./bonus/checkarg_bonus.c \
			./bonus/utils_bonus.c \
			./bonus/init_bonus.c \

OBJS= $(SRCS:.c=.o)
OBJS_BONUS= $(SRC_BONUS:.c=.o)

NAME= fractol
NAME_BONUS = fractol_bonus

LIBFT_A= ./libft/libft.a
MLX_A= ./minilibx/libmlx.a

all: libft mlx $(NAME)

$(OBJS):%.o:%.c $(MLX_A)
	cc $(CFLAGS) -I./minilibx -c $< -o $@

$(OBJS_BONUS):%.o:%.c $(MLX_A)
	cc $(CFLAGS) -I./minilibx -c $< -o $@

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) $(LIBFT_A) $(MLX_A) $(MLX_FLAGS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	cc $(CFLAGS) $(OBJS_BONUS) $(LIBFT_A) $(MLX_A) $(MLX_FLAGS) -o $(NAME_BONUS)

bonus: libft mlx $(NAME_BONUS)

libft:
	make -C ./libft

mlx:
	make -C ./minilibx

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	make clean -C ./minilibx
	make clean -C ./libft 

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -f $(LIBFT_A)
	rm -f $(MLX_A)

re: fclean all

.PHONY: clean fclean re libft mlx all bonus