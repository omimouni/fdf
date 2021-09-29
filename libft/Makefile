# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 17:58:07 by omimouni          #+#    #+#              #
#    Updated: 2021/09/30 00:03:50 by omimouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCDIR = ../include
OBJDIR = ../build

SRCS = $(wildcard src/*.c src/**/*.c)
OBJS = $(patsubst src/%.c,$(OBJDIR)/libft/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(OBJDIR)/libft

re: fclean all
	
$(OBJDIR)/libft/%.o: src/%.c
	mkdir -p $(dir $@)
	gcc $< -I$(INCDIR) -g -fsanitize=address -c -o $@