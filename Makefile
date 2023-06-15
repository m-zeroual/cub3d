SRCS	= 	src/ft_display_map.c \
			src/main.c \
			src/ft_error.c \
			src/ft_utils.c \
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

