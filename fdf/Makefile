RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m

NAME = fdf

LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

MLX_DIR = ./mlx
MLX_PATH = ${MLX_DIR}/libmlx.a
MLX = MLX =  -L /usr/lib -lXext -lX11 -lm -lz
MLX_OBJ = -I/usr/include -Imlx_linux -O3
MLX_LIB = -L $(MLX_DIR) -lmlx

SRCS = source/main.c source/window.c source/error_management.c \
	   source/parse.c source/get_next_line.c source/get_next_line_utils.c \
	   source/free.c source/count.c source/draw.c source/projection.c

OBJS = $(SRCS:srcs.c=srcs.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_DIR)
	@make -C libft
	@printf "                                           \r"
	@echo "                 							"
	@echo "\033[0;34m 	███████╗ ██████╗   ███████╗     "
	@echo "\033[0;34m	██╔════╝ ██╔══██╗  ██╔════╝		"
	@echo "\033[0;34m	█████╗   ██║  ██║  █████╗  		"
	@echo "\033[0;34m	██╔══╝   ██║  ██║  ██╔══╝  		"
	@echo "\033[0;34m	██║      ██████╔╝  ██║     		"
	@echo "\033[0;34m	╚═╝      ╚═════╝   ╚═╝  		"
	@echo "                 							"
	@$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -g $(MLX_LIB) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean : clean
	@make fclean -C libft
	@$(RM) fdf

clean :
	@make clean -C libft
	@$(RM) source/*.o

re : fclean all 

.PHONY: all clean fclean re