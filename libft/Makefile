NAME = libft.a

SRCDIR = .
OBJDIR = .

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

BSOURCES = ""
BOBJECTS = $(BSOURCES:.c=.o)


CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address -fsanitize=undefined

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $?

bonus: $(OBJECTS) $(BOBJECTS)
	$(AR) -r $(NAME) $?

$(OBJECTS) : $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME)
	rm a.out

re: fclean all

test: $(NAME)
	$(CC) tests/test.c  $(CFLAGS)  $(NAME)

.PHONY: all bonus clean fclean re