# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuddu <apuddu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 18:13:07 by apuddu            #+#    #+#              #
#    Updated: 2024/11/20 13:42:11 by apuddu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bank_logger

SOURCES  := $(wildcard *.cpp)

OBJECTS = $(SOURCES:.cpp=.o)

CC = c++
CFLAGS = -O3 -Wall -Wextra -Werror  -std=c++98 #-fsanitize=address -fsanitize=undefined

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) $(CFLAGS)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $? -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re
