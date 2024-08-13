NAME = fdf

SRCDIR = .
OBJDIR = .

SOURCES  := $(wildcard src/*.c) $(wildcard libft/*.c) $(wildcard libft/vector/*.c) 
MAIN_SOURCES = $(wildcard main/*.c)
BONUS_SOURCES = $(wildcard bonus/*.c)

OBJECTS = $(SOURCES:.c=.o)
MAIN_OBJECTS = $(MAIN_SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -g -I./libft -I./src -I./minilibx-linux -Werror  -fsanitize=address -fsanitize=undefined

all: $(NAME)

$(NAME): $(OBJECTS) $(MAIN_OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) $(MAIN_OBJECTS) $(CFLAGS) -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) -c $(CFLAGS) $? -o $@

clean:
	rm -f $(OBJECTS) $(MAIN_OBJECTS) $(BONUS_OBJECTS)
	make clean -C libft 

fclean: clean
	rm -f $(NAME)
	make fclean -C libft 


re: fclean all 

.PHONY: all bonus clean fclean re libft
