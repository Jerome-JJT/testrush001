# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaqueme <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 09:31:22 by jjaqueme            #+#    #+#              #
#    Updated: 2021/01/08 11:55:09 by jjaqueme           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRC	=	push_swap.c \
		push_swap2.c \
	input_check.c \
	algo_small.c \
	array_handle.c \
	array_handle2.c \
	array_handle3.c \
	algo.c \
	ft_minilibft.c \
	ft_split_shit.c \
	too_long.c \
	algo_simple.c \
	replace_double.c

SRC_BONUS	=	checker.c \
			checker2.c \
			input_check.c \
			algo_small.c \
			array_handle.c \
			array_handle2.c \
			array_handle3.c \
			algo.c \
			ft_minilibft.c \
			ft_minilibft2.c \
			ft_split_shit.c \
			too_long.c \
			algo_simple.c \
			replace_double.c \
			get_next_line.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC      = gcc
RM      = rm -f

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

bonus:	$(NAME_BONUS)

$(NAME): ${OBJ}
	$(CC) $(CFLAGS) -g -o $(NAME) ${OBJ}

$(NAME_BONUS): ${OBJ_BONUS}
	$(CC) $(CFLAGS) -g -o $(NAME_BONUS) ${OBJ_BONUS}

clean:
		${RM} ${OBJ}
		${RM} ${OBJ_BONUS}

fclean: clean
		${RM} ${NAME}
		${RM} ${NAME_BONUS}

re:		fclean all

.PHONY: all bonus clean fclean re