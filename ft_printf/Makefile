# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timanish <timanish@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 21:56:14 by timanish          #+#    #+#              #
#    Updated: 2024/05/27 14:34:16 by timanish         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFRAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = 	ft_putword.c\
		ft_printf.c\
		
OBJS = $(SRCS:.c=.o)

INCLUDES = -I includes

$(NAME) :    $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o:%.c
	$(CC) -c  $(CFLAGS) $^ -o $@ $(INCLUDES)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re