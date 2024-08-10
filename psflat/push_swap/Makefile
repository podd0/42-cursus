NAME = push_swap

SRCDIR = .
OBJDIR = .

SOURCES  :=  algo2.c         ft_calloc.c   ft_memcmp.c      ft_split.c     ft_strmapi.c  get_next_line.c        stack_operations.c  vi_0.c   vlu_2.c \
		algo3.c         ft_isalnum.c  ft_memcpy.c      ft_strchr.c    ft_strncmp.c  get_next_line_utils.c  to_string.c         vi_1.c   vstr_0.c \
		algo.c          ft_isalpha.c  ft_memmove.c     ft_strdup.c    ft_strnstr.c                utils2.c            vi_2.c   vstr_1.c \
		ft_isascii.c  ft_memset.c      ft_striteri.c  ft_strrchr.c  printf.c               utils3.c            vl_0.c   vstr_2.c \
		consolidate2.c  ft_isdigit.c  ft_putchar_fd.c  ft_strjoin.c   ft_strtrim.c  printf_utils.c         utils5.c            vl_1.c \
		consolidate.c   ft_isprint.c  ft_putendl_fd.c  ft_strlcat.c   ft_substr.c   safe_alloc.c           utils6.c            vl_2.c \
		ft_atoi.c       ft_itoa.c     ft_putnbr_fd.c   ft_strlcpy.c   ft_tolower.c  sort.c                 utils7.c            vlu_0.c \
		ft_bzero.c      ft_memchr.c   ft_putstr_fd.c   ft_strlen.c    ft_toupper.c  stack_operations2.c    utils.c             vlu_1.c
MAIN_SOURCES = main.c
BONUS_SOURCES = bonus.c

IDIR := printf
OBJECTS = $(SOURCES:.c=.o)
MAIN_OBJECTS = $(MAIN_SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -g -I./libft -I. -I./src -Werror # -fsanitize=address -fsanitize=undefined

all: $(NAME)

$(NAME): $(OBJECTS) $(MAIN_OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) $(MAIN_OBJECTS) $(CFLAGS)

bonus: checker

checker: $(OBJECTS) $(BONUS_OBJECTS)
	$(CC) -o checker $(OBJECTS) $(BONUS_OBJECTS) $(CFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $? -o $@

clean:
	rm -f $(OBJECTS) $(MAIN_OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME)


re: fclean all 

.PHONY: all bonus clean fclean re libft
