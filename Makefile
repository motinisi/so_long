# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timanish <timanish@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 15:37:03 by timanish          #+#    #+#              #
#    Updated: 2024/10/07 13:48:02 by timanish         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = so_long
SRCS = main.c\
		so_long_utils.c\
		get_next_line.c\
		get_next_line_utils.c\
		create_screen.c\
		key_hook.c\
		error_check.c\
		error_utils.c\
		free.c\

OBJS = $(SRCS:.c=.o)

INCLUDES = -I includes

all: $(NAME)

$(NAME): $(OBJS)
	@make -C "libft"
	@make -C "minilibx-linux"
	$(CC) -o $(NAME) $(OBJS) libft/libft.a minilibx-linux/libmlx.a -lX11 -lXext -lm

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)
	@make -C "libft" clean
	@make -C "minilibx-linux" clean

fclean: clean
	rm -f $(NAME)
	@make -C "libft" fclean
	@make -C "minilibx-linux" clean

re: fclean all

.PHONY: all clean fclean re
