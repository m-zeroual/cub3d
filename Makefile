SRCS	= 	src/check_map/ft_display_map.c \
			src/main.c \
			src/check_map/check_error/ft_error.c \
			src/check_map/parse_map.c \
			src/check_map/check_error/ft_check6lines.c \
			src/check_map/ft_utils.c \
			lib/get_next_line/get_next_line.c \
			lib/get_next_line/get_next_line_utils.c

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

NAME	= libft.a

PATH_LIB = lib/libft/

OBJS	= $(SRCS:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJS)
		make -C $(PATH_LIB)
		$(CC) $(CFLAGS) $(PATH_LIB)libft.a $(OBJS) -o cub3d

.o:.c
			$(CC) $(CFLAGS)  -c $^ -o $@

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

bonus:		$(OBJS_BONUS)
			ar rcs $(NAME) $(OBJS_BONUS)

