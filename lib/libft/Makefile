# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzeroual <mzeroual@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 22:44:27 by mzeroual          #+#    #+#              #
#    Updated: 2022/10/24 23:38:28 by mzeroual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_split.c ft_striteri.c ft_strmapi.c ft_putnbr_fd.c ft_putendl_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_itoa.c ft_strtrim.c ft_substr.c ft_strjoin.c ft_calloc.c ft_strdup.c ft_isalpha.c ft_isdigit.c ft_memmove.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_atoi.c  ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

NAME	= libft.a


OBJS	= $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $@ $^

%.o:%.c
			$(CC) $(CFLAGS)  -c $^ -o $@

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

bonus:		$(OBJS_BONUS)
			ar rcs $(NAME) $(OBJS_BONUS)

