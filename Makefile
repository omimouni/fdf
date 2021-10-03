# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 18:27:52 by omimouni          #+#    #+#              #
#    Updated: 2021/10/03 13:07:49 by omimouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = $(wildcard src/*.c src/**/*.c)
OBJS = $(addprefix build/, $(patsubst src/%.c, %.o, $(SRCS)))
LIBFT = libft/libft.a


# MLX flags based on OS
OS := $(shell uname)
ifeq ($(OS),Linux)
LIB_FLAGS =  -lm -lmlx -lX11 -lXext 
endif
ifeq ($(OS),Darwin)
LIB_FLAGS = -lm -lmlx -framework OpenGL -framework AppKit
endif

FLAGS = -fsanitize=leak

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	gcc $(OBJS) $(LIBFT) $(LIB_FLAGS) $(FLAGS) -o $(NAME)

clean: 
	rm -rf $(OBJS)
	make -sC ./libft clean

fclean: clean
	rm -rf build/
	rm -rf $(NAME)
	make -sC ./libft fclean

re: fclean all

$(LIBFT):
	make -sC ./libft
	
build/%.o: src/%.c
	mkdir -p $(dir $@)
	gcc $< -I./include $(FLAGS) -c -o $@