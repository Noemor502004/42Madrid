all: libft.a

SRCS = ft_atoi.c \
ft_bzero.c \
ft
OBJS = $(SRCS:.c=.o)

libft.a: $(OBJS)
	ar rcs libft.a $(OBJS)

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -rf *.o

fclean:
	rm -rf *.o libft.a

re: fclean all