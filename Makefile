# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 13:12:29 by mzeroual          #+#    #+#              #
#    Updated: 2023/08/15 14:54:30 by mzeroual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_GET_NEXT_LINE = lib/get_next_line/


SRCS_BONUS= 	bonus/src/main.c \
				bonus/src/check_map/ft_free_map.c \
				bonus/src/check_map/check_error/ft_error.c \
				bonus/src/check_map/parse_map.c \
				bonus/src/check_map/check_error/ft_check6lines.c \
				bonus/src/check_map/ft_utils.c \
				bonus/src/cub3d/ft_draw_map.c \
				bonus/src/cub3d/control_hooks.c \
				bonus/src/cub3d/cub3d_utils.c \
				bonus/src/cub3d/rays_casting.c \
				bonus/src/cub3d/ft_calcul_raycasting.c \
				bonus/src/cub3d/is_door.c \
				bonus/src/cub3d/cub3d_utils2.c \
				bonus/src/cub3d/cub3d.c \
				$(PATH_GET_NEXT_LINE)get_next_line.c \
				$(PATH_GET_NEXT_LINE)get_next_line_utils.c

SRCS 	  =	    mandatory/src/main.c \
				mandatory/src/check_map/ft_free_map.c \
				mandatory/src/check_map/check_error/ft_error.c \
				mandatory/src/check_map/parse_map.c \
				mandatory/src/check_map/check_error/ft_check6lines.c \
				mandatory/src/check_map/ft_utils.c \
				mandatory/src/cub3d/ft_draw_map.c \
				mandatory/src/cub3d/control_hooks.c \
				mandatory/src/cub3d/cub3d_utils.c \
				mandatory/src/cub3d/rays_casting.c \
				mandatory/src/cub3d/ft_calcul_raycasting.c \
				mandatory/src/cub3d/cub3d_utils2.c \
				mandatory/src/cub3d/cub3d.c \
				$(PATH_GET_NEXT_LINE)get_next_line.c \
				$(PATH_GET_NEXT_LINE)get_next_line_utils.c



CC		= cc

CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address

RM		= rm -f

NAME	= cub3d

NAME_BONUS	= cub3d_bonus

PATH_LIB = lib/libft/

OBJS	= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all:	$(NAME)

$(NAME):$(OBJS)
		make -C $(PATH_LIB)
		$(CC) $(CFLAGS) $(PATH_LIB)libft.a $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o:%.c ./include/cub3d.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		make clean -C $(PATH_LIB)
		$(RM) $(OBJS)
		$(RM) $(OBJS_BONUS)

fclean:	clean
		make fclean -C $(PATH_LIB)
		$(RM) $(NAME)
		$(RM) $(NAME_BONUS)

re:		fclean all

bonus: $(OBJS_BONUS)
		make -C $(PATH_LIB)
		$(CC) $(CFLAGS) $(PATH_LIB)libft.a $(OBJS_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

