# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschmitz <eschmitz@students.s19.be>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 14:42:37 by eschmitz          #+#    #+#              #
#    Updated: 2024/04/04 17:18:00 by eschmitz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = srcs/*.c
OBJS = $(SRCS:.c=.o)
PROG = libft.a

INCLUDE = includes/

all = $(PROG)

$(PROG) : $(OBJS)
	ar rc $(PROG) $(OBJS)
	ranlib $(PROG)

%.o : %.c
	$(CC) $(CLFAGS) -c $< -I $(INCLUDE)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(PROG)

re : fclean all

.PHONY : all clean fclean re
