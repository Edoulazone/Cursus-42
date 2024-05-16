NAME=libftprintf.a
LIBFT=Libft/libft.a

SRCS=ft_printf.c ft_printer.c
OBJS=$(SRCS:.c=.o)


CC=gcc
CFLAGS=-Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	cp Libft/libft.a $(NAME)
	ar rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJS)
	make $@ -C Libft

fclean: clean
	rm -f $(NAME)
	make $@ -C Libft

re: fclean all

.PHONY: all clean fclean re bonus