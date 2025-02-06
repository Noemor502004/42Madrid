# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 17:17:57 by nmorgado          #+#    #+#              #
#    Updated: 2025/02/03 18:42:54 by nmorgado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = deal_with_hex.c \
deal_with_int.c \
deal_with_letters.c \
deal_with_unsig.c \
deal_with_void.c \
ft_uitoa.c \
ft_make_hex.c \
ft_printf.c \
ft_realloc.c \
ft_str_reverse.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft all
	cp libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJS)

fclean:
	$(MAKE) -C libft fclean
	rm -rf $(OBJS) $(NAME)

re: fclean all
