**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 22:54:39 by cmarouf           #+#    #+#              #
#    Updated: 2021/12/04 13:26:49 by cmarouf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS 		= 

OBJS 		= $(SRCS:.c=o)

RM 			= rm -f

CFLAGS 		= -Wall -Wextra -Werror

NAME		= so_long

LIBFT_PATH	= libft/

MLX_LIB		= gmlx

LIBFT		= ${LIBFT_PATH}libft.a

CC 			= gcc

all:		$(NAME)

libcompilator:
	make $(LIBFT_PATH) all

$(NAME): 

compilator:
	$(CC) $(CFLAGS) $(MLX_LIB) $(OBJS) $(LIBFT_LIB) -o $(NAME)

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} $(NAME)

re:			fclean all

.PHONY: all clean fclean re bonus 
