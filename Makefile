# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehida <ehida@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 14:04:02 by ehida             #+#    #+#              #
#    Updated: 2023/07/04 19:38:30 by ehida            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= main.c ft_parse.c ft_exit.c ft_utils.c ft_moves.c ft_sort.c \
			ft_sort_utils.c

OBJ	= $(SRC:%.c=%.o)

NAME	= push_swap

CC		= cc
FLAGS	= -Wextra -Werror -Wall

RM		= /bin/rm -f

LIBFT	= libft/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	make -C libft

$(OBJ): %.o: %.c
	$(CC) $(FLAGS) -c $?

clean:
	$(RM) $(OBJ)
	cd libft && $(MAKE) clean

fclean: clean
	$(RM) $(NAME)
	cd libft && $(MAKE) fclean

re: fclean all
