# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuddu <apuddu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 18:13:07 by apuddu            #+#    #+#              #
#    Updated: 2024/10/29 19:54:06 by apuddu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCDIR = .
OBJDIR = .

SOURCES  := atoi.c  main.c  philosopher.c  philosopher_utils.c  utils.c

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I. -pthread

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) $(CFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $? -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all bonus clean fclean re libft
