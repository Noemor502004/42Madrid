all: libft.a

SRCS = $(wildcard *.c)
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