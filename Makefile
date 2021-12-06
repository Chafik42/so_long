# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 22:54:39 by cmarouf           #+#    #+#              #
#    Updated: 2021/12/06 13:02:38 by cmarouf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS 		=  main.c

RM 			= rm -f

CFLAGS 		= -Wall -Wextra -Werror

NAME		= so_long

LIBFT_PATH	= ./libft/

GNL_PATH	= get_next_line/

MLX_LIB		= -I/usr/include -Imlx_linux -O3 -c $< -o $@

LIBFT		= ${LIBFT_PATH}libft.a

GNL			= ${GNL_PATH}gnl.a

CC 			= gcc

all:

libcompilator:
	make -C $(LIBFT_PATH)
	make -C $(GNL_PATH)
	mv ${LIBFT_PATH}${LIBFT_LIB} 

compilator:
	$(CC) $(CFLAGS) $(SRCS) $(MLX_LIB) $(LIBFT_LIB) $(GNL_PATH) -o $(NAME)

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} $(NAME) ${LIBFT_LIB} ${GNL_PATH}

re:			fclean all

.PHONY: all clean fclean re bonus 
