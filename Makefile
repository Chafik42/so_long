# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 22:54:39 by cmarouf           #+#    #+#              #
#    Updated: 2021/12/05 00:09:14 by cmarouf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS 		=  main.c

RM 			= rm -f

CFLAGS 		= -Wall -Wextra -Werror

NAME		= so_long

LIBFT_PATH	= libft/

GNL_PATH	= get_next_line/

MLX_LIB		= gmlx

LIBFT		= ${LIBFT_PATH}libft.a

GNL			= ${GNL_PATH}gnl.a

CC 			= gcc

all:

libcompilator:
	make $(LIBFT_PATH)
	make $(GNL_PATH)

compilator:
	$(CC) $(CFLAGS) $(SRCS) $(MLX_LIB) $(LIBFT_LIB) $(GNL_PATH) -o $(NAME)

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} $(NAME)

re:			fclean all

.PHONY: all clean fclean re bonus 