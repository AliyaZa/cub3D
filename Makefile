# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhill <nhill@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/22 18:16:32 by nhill             #+#    #+#              #
#    Updated: 2021/03/16 14:30:30 by nhill            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = utils.c sprite.c save.c read_map.c re_errors.c raycasting.c position.c path.c parse_map.c init.c header.c get_next_line.c get_data.c \
		free.c events.c display.c cub3d.c colour.c check_data.c add_sprite.c move.c map_check.c

OBJS	= ${SRCS:.c=.o}

LIBFT	= libft/libft.a

MINILIBX= minilibx_opengl_20191021/libmlx.a

CFLAGS	=	-Wall -Werror -Wextra

%.o: %.c	gcc $(CFLAGS) -o $@ -c $<

$(NAME):	${OBJS}
			make -C minilibx_opengl_20191021
			make -C libft
			gcc -framework OpenGL -framework AppKit -g -o $(NAME) $(OBJS) $(LIBFT) $(MINILIBX)

all:		${NAME}

clean:
			rm -f ${OBJS}
			make clean -C libft

fclean:		clean
			rm -f ${NAME} cub.bmp
			make clean -C minilibx_opengl_20191021
			make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean
