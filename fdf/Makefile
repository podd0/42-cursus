# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuddu <apuddu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 18:13:07 by apuddu            #+#    #+#              #
#    Updated: 2024/09/03 18:13:08 by apuddu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
BONUS = fdf_bonus
SRCDIR = .
OBJDIR = .
MLX = minilibx-linux/libmlx.a

SOURCES  := src/atoi_mod.c src/controller2.c src/controller.c src/frame2.c src/frame.c src/grid_0.c src/grid_1.c src/grid_2.c src/image_utils.c src/matrix.c src/parse2.c src/parse.c\
			src/point_urils.c src/render2.c src/render_aa.c src/render.c src/render_persp.c src/rot.c src/vec3f_2.c src/vec3f.c src/vector_utils.c src/vvec_0.c src/vvec_1.c src/vvec_2.c  \
			libft/vector/vi_0.c libft/vector/vi_1.c libft/vector/vi_2.c libft/vector/vl_0.c libft/vector/vl_1.c libft/vector/vl_2.c libft/vector/vlu_0.c libft/vector/vlu_1.c libft/vector/vlu_2.c\
			libft/vector/vstr_0.c libft/vector/vstr_1.c libft/vector/vstr_2.c libft/vector/vu_0.c libft/vector/vu_1.c libft/vector/vu_2.c libft/vector/vvu_0.c libft/vector/vvu_1.c libft/vector/vvu_2.c \
			libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_memchr.c \
			libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c \
			libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c \
			libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c libft/get_next_line.c libft/get_next_line_utils.c libft/max_min.c libft/printf.c libft/printf_utils.c libft/safe_alloc.c libft/to_string.c  
MAIN_SOURCES = main/main.c
BONUS_SOURCES = bonus/main.c

OBJECTS = $(SOURCES:.c=.o)
MAIN_OBJECTS = $(MAIN_SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

CC = gcc
CFLAGS = -O3 -Wall -Wextra -g -I./libft -I./src -I./minilibx-linux -Werror #-fsanitize=address -fsanitize=undefined

all: $(NAME)

$(MLX):
	make -C minilibx-linux

$(NAME): $(OBJECTS) $(MAIN_OBJECTS) $(MLX)
	$(CC) -o $(NAME) $(OBJECTS) $(MAIN_OBJECTS) $(CFLAGS) -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

bonus: fdf_bonus

$(BONUS):  $(OBJECTS) $(BONUS_OBJECTS) $(MLX)
	$(CC) -o $(BONUS) $(OBJECTS) $(BONUS_OBJECTS) $(CFLAGS) -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) -c $(CFLAGS) $? -o $@

clean:
	rm -f $(OBJECTS) $(MAIN_OBJECTS) $(BONUS_OBJECTS)
	make clean -C libft 
	make clean -C minilibx-linux

fclean: clean
	rm -f $(NAME) $(BONUS)
	make fclean -C libft 


re: fclean all 

.PHONY: all bonus clean fclean re libft
