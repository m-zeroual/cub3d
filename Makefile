# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 13:12:29 by mzeroual          #+#    #+#              #
#    Updated: 2023/07/26 15:50:03 by kchaouki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_GET_NEXT_LINE = lib/get_next_line/


SRCS	= 	src/main.c \
			src/check_map/ft_free_map.c \
			src/check_map/check_error/ft_error.c \
			src/check_map/parse_map.c \
			src/check_map/check_error/ft_check6lines.c \
			src/check_map/ft_utils.c \
			src/cub3d/ft_display_map.c \
			src/cub3d/draw_line.c \
			src/cub3d/cub3d.c \
			src/cub3d/control_hooks.c \
			$(PATH_GET_NEXT_LINE)get_next_line.c \
			$(PATH_GET_NEXT_LINE)get_next_line_utils.c


CC		= cc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

NAME	= cub3d

PATH_LIB = lib/libft/

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):$(OBJS) include/cub3d.h
		make -C lib/minilibx_opengl_20191021
		make -C $(PATH_LIB)
		$(CC) $(CFLAGS) $(PATH_LIB)libft.a  lib/minilibx_opengl_20191021/libmlx.a $(OBJS) -framework OpenGL -framework AppKit -o $(NAME)

%.o:%.c
		$(CC) $(CFLAGS)  -c $^ -o $@

# bonus:

clean:
		make clean -C $(PATH_LIB)
		$(RM) $(OBJS)

fclean:	clean
		make fclean -C $(PATH_LIB)
		make clean -C lib/minilibx_opengl_20191021
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY: all clean fclean re bonus