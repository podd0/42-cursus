NAME = push_swap
LIBFT = libft/libft.a

SRCDIR = .
OBJDIR = .

SOURCES  := $(wildcard *.c)

IDIR := printf
OBJECTS = $(SOURCES:.c=.o) 

CC = gcc
CFLAGS = -Wall -Wextra  -g -I./libft -I. -Werror # -fsanitize=address -fsanitize=undefined

all: $(NAME)

libft:
	make -C libft

$(NAME): $(OBJECTS) libft
	$(CC) -o $(NAME) $(OBJECTS) $(LIBFT) $(CFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)
	make clean -C libft 

fclean: clean
	rm -f $(NAME)
	make fclean -C libft 

re: fclean all 

.PHONY: all bonus clean fclean re libft