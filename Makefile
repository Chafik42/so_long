# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 02:59:13 by cmarouf           #+#    #+#              #
#    Updated: 2021/12/12 00:47:44 by cmarouf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./srcs/main.c			 \
	   ./srcs/input.c			 \
	   ./srcs/filecheck.c		 \
	   ./srcs/init_map_player.c  \
	   ./srcs/parsing.c			 \
	   ./srcs/print.c			 \
	   ./srcs/utils.c			 \
	   ./srcs/animation.c		 \
	   ./srcs/player_animation.c \

OBJS = ${SRCS:.c=.o}

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

BONUS = 0

MLXFLAGS = ./minilibx/libmlx_Linux.a -lXext -lX11 -I ./minilibx/ 

NAME = so_long

CC = gcc

ifdef WITH_BONUS
BONUS = 1
endif

.c.o:
	${CC} -I includes ${CFLAGS} -D BONUS=$(BONUS) -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./minilibx
	$(CC) $(CFLAGS) -D BONUS=$(BONUS) $(OBJS) $(MLXFLAGS) -o $(NAME)

clean:
		$(RM) ${OBJS}
		make clean -C ./minilibx

fclean: clean
		$(RM) $(NAME)
		$(RM) ./minilibx/libmlx_Linux.a
		$(RM) ./minilibx/libmlx.a

bonus :
	$(MAKE) WITH_BONUS=1

re:	fclean all

.PHONY: all clean fclean re bonus
