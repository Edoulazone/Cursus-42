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

MLX_DIR = mlx
MLX_PATH = ${MLX_DIR}/libmlx.a
MLX = -lmlx -Lmlx -framework OpenGl -framework AppKit $(MLX_PATH)
MLX_OBJ = -I/usr/include -Imlx_linux -O3

INCLUDE = -I includes -I mlx

SRCS_DIR = srcs
SRCS = $(SRCS_DIR)/main.c $(SRCS_DIR)/parse.c\
			$(SRCS_DIR)/window.c $(SRCS_DIR)/draw.c\
			$(SRCS_DIR)/error_management.c\
			$(SRCS_DIR)/get_next_line.c\
			$(SRCS_DIR)/get_next_line_utils.c\
			$(SRCS_DIR)/projection.c\
			$(SRCS_DIR)/free.c $(SRCS_DIR)/count.c

OBJS = $(SRCS:$(SRCS_DIR).c=$(SRCS_DIR).o)

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
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX) $(INCLUDE) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	@make clean -C libft
	@$(RM) $(OBJS)
	@make clean -C mlx

fclean: clean
	@make fclean -C libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re