# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 18:27:52 by omimouni          #+#    #+#              #
#    Updated: 2021/09/28 18:36:53 by omimouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = $(wildcard src/*.c src/**/*.c)
OBJS = $(addprefix build/, $(patsubst src/%.c, %.o, $(SRCS)))

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(OBJS)  -lmlx -lX11 -lXext -o $(NAME)

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf build/
	rm -rf $(NAME)

re: fclean all

build/%.o: src/%.c
	mkdir -p $(dir $@)
	gcc $< -I./include  -c -o $@