# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 23:50:24 by cmarouf           #+#    #+#              #
#    Updated: 2021/12/05 00:00:45 by cmarouf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		= ./get_next_line.c 	\
			  ./get_next_line_utils.c \

OBJS 		= ${SRCS:.c=.o}

RM 			= rm -f

CFLAGS 		= -Wall -Wextra -Werror

NAME		= gnl.a

CC 			= gcc

.c.o:
	${CC} -I includes ${CFLAGS} -D BUFFER_SIZE=1 -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME): 	${OBJS}
	ar -rcs $(NAME) ${OBJS}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} $(NAME)

re:			fclean all

.PHONY: all clean fclean re  
