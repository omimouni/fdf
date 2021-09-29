# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 18:27:52 by omimouni          #+#    #+#              #
#    Updated: 2021/09/29 10:08:50 by omimouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = $(wildcard src/*.c src/**/*.c)
OBJS = $(addprefix build/, $(patsubst src/%.c, %.o, $(SRCS)))


# MLX flags based on OS
OS := $(shell uname)
ifeq ($(OS),Linux)
LIB_FLAGS = -lmlx -lX11 -lXext 
endif
ifeq ($(OS),Darwin)
LIB_FLAGS = -lmlx -framework OpenGL -framework AppKit
endif


all: $(NAME)

$(NAME): $(OBJS)
	gcc $(OBJS) $(LIB_FLAGS) -o $(NAME)

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf build/
	rm -rf $(NAME)

re: fclean all

build/%.o: src/%.c
	mkdir -p $(dir $@)
	gcc $< -I./include  -c -o $@