# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timanish <timanish@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 15:37:03 by timanish          #+#    #+#              #
#    Updated: 2024/10/07 14:09:52 by timanish         ###   ########.fr        #
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
	@make -C "ft_printf"
	@make -C "minilibx-linux"
	$(CC) -o $(NAME) $(OBJS) libft/libft.a ft_printf/libftprintf.a minilibx-linux/libmlx.a -lX11 -lXext -lm

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)
	@make -C "libft" clean
	@make -C "ft_printf" clean
	@make -C "minilibx-linux" clean

fclean: clean
	rm -f $(NAME)
	@make -C "libft" fclean
	@make -C "ft_printf" fclean
	@make -C "minilibx-linux" clean

re: fclean all

.PHONY: all clean fclean re
