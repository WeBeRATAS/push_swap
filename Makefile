# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 09:53:34 by rbuitrag          #+#    #+#              #
#    Updated: 2024/10/02 13:42:14 by rbuitrag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra -Iinc

MODE = null
HEADER = inc/push_swap.h
LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a

CFILES =  main.c\
		  check_args.c\
          sort_stacks.c\
          sort_three.c\
          stack_init.c\
          stack_utils.c\
		  push.c\
		  swap.c\
		  reverse_rotate.c\
		  rotate.c\
		  sort_utils.c\
		  		  
OBJS = $(addprefix src/, $(CFILES:.c=.o))

ifeq ($(MODE), debug)
	CFLAGS += -g
endif

all: library $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

library:
	@make -C libft
	@make -C printf
	
clean:
	@make clean -C printf
	@make clean -C libft
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C printf
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re library
