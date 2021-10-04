# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 18:27:52 by omimouni          #+#    #+#              #
#    Updated: 2021/10/04 11:31:27 by omimouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
NAME_BONUS = fdf_bonus

SRCS =	src/fdf.c\
				src/parser/init.c\
				src/parser/map.c\
				src/engine/gradient.c\
				src/engine/draw_line.c\
				src/engine/mlx.c\
				src/engine/responsive.c\
				src/engine/key_hooks.c\
				src/engine/render.c

OBJS =	build/fdf.o\
				build/parser/init.o\
				build/parser/map.o\
				build/engine/gradient.o\
				build/engine/draw_line.o\
				build/engine/mlx.o\
				build/engine/responsive.o\
				build/engine/key_hooks.o\
				build/engine/render.o

OBJS_BONUS =	build/bonus/fdf.o\
				build/bonus/parser/init.o\
				build/bonus/parser/map.o\
				build/bonus/engine/gradient.o\
				build/bonus/engine/draw_line.o\
				build/bonus/engine/mlx.o\
				build/bonus/engine/responsive.o\
				build/bonus/engine/key_hooks.o\
				build/bonus/engine/render.o

LIBFT = libft/libft.a


# MLX flags based on OS
OS := $(shell uname)
ifeq ($(OS),Linux)
LIB_FLAGS =  -lm -lmlx -lX11 -lXext 
endif
ifeq ($(OS),Darwin)
LIB_FLAGS = -lm -lmlx -framework OpenGL -framework AppKit
endif

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	gcc $(OBJS) $(LIBFT) $(LIB_FLAGS) $(FLAGS) -DIS_BONUS=1 -o $(NAME)
	
clean: 
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)
	make -sC ./libft clean

fclean: clean
	rm -rf build/
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	make -sC ./libft fclean

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	gcc $(OBJS_BONUS) $(LIBFT) $(LIB_FLAGS) $(FLAGS) -D IS_BONUS=1 -o $(NAME_BONUS)


$(LIBFT):
	make -sC ./libft
	
build/%.o: src/%.c
	mkdir -p $(dir $@)
	gcc $< -I./include $(FLAGS) -DIS_BONUS=1 -c -o $@

	
build/bonus/%.o: src/%.c
	mkdir -p $(dir $@)
	gcc $< -I./include $(FLAGS) -DIS_BONUS=1 -c -o $@