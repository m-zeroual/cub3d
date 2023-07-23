# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 13:12:29 by mzeroual          #+#    #+#              #
#    Updated: 2023/07/23 19:01:41 by mzeroual         ###   ########.fr        #
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
			src/cub3d/cub3d.c \
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
		make -C $(PATH_LIB)
		$(CC) $(CFLAGS) $(PATH_LIB)libft.a $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o:%.c
		$(CC) $(CFLAGS)  -c $^ -o $@

clean:
		make clean -C $(PATH_LIB)
		$(RM) $(OBJS)

fclean:	clean
		make fclean -C $(PATH_LIB)
		$(RM) $(NAME)

re:		fclean $(NAME)
