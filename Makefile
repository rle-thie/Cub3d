# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 22:32:51 by rle-thie          #+#    #+#              #
#    Updated: 2022/12/12 23:44:02 by ldevy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${SRCS_MAIN} ${SRCS_INITS} ${SRCS_LIBFT} ${SRCS_GAME} ${SRCS_GNL} ${SRCS_PARSING}

SRCS_MAIN = $(addprefix srcs/, main.c)

SRCS_GNL = $(addprefix srcs/gnl/, ft_get_next_line.c)

SRCS_PARSING = $(addprefix srcs/parsing/, parsing_one.c utils.c)

SRCS_INITS = $(addprefix srcs/init/, init.c gc.c gc_utils.c)

SRCS_GAME = $(addprefix srcs/game/, ray_casting.c raycastin_utils.c draw.c move.c)

SRCS_LIBFT = $(addprefix srcs/libft/, ft_putstr_fd.c ft_bzero.c ft_strdup.c ft_strlen.c convert_trgb.c\
				ft_strjoin_gc.c ft_strchr.c ft_strncmp.c ft_split.c ft_strtrim.c ft_atoi.c)

OBJDIR = objs

OBJS = $(addprefix ${OBJDIR}/, ${SRCS:.c=.o})

NAME = cub3D

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -fr

all: ${NAME}

${NAME}:	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -I/usr/include -Imlx -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $@ 

${OBJDIR}/%.o:%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -c $< -o $@ 

clean:
	${RM} ${OBJS}
	${RM} ${OBJDIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

v: re
	valgrind ./${NAME} maps/caca.cub

rc: fclean all
	${RM} ${OBJS} && clear

n :
	norminette srcs include

.PHONY: all clean fclean re