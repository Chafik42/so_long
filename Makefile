# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 02:59:13 by cmarouf           #+#    #+#              #
#    Updated: 2021/12/09 03:36:54 by cmarouf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c			 \
	   input.c			 \
	   filecheck.c		 \
	   init_map_player.c \
	   parsing.c		 \
	   print.c			 \
	   utils.c			 \

OBJS = ${SRCS:.c=.o}

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = ./minilibx/libmlx_Linux.a -lmlx -lXext -lX11 -I ./minilibx/ 

NAME = so_long

CC = gcc

.c.o:
	${CC} -I includes ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./minilibx
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

clean:
		$(RM) ${OBJS}

fclean: clean
		$(RM) $(NAME)
re:	fclean all

.PHONY: all clean fclean re bonus
