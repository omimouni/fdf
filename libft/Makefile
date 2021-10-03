# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 17:58:07 by omimouni          #+#    #+#              #
#    Updated: 2021/10/03 20:25:49 by omimouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCDIR = ../include
OBJDIR = ../build

SRCS =	src/ft_gnl/ft_gnl.c\
				src/utils/ft_substr.c\
				src/utils/ft_strchr.c\
				src/utils/ft_strdup.c\
				src/utils/ft_strlen.c\
				src/utils/ft_split.c\
				src/utils/ft_strjoin.c\
				src/utils/ft_atoi.c

OBJS =	../build/libft/ft_gnl/ft_gnl.o\
				../build/libft/utils/ft_substr.o\
				../build/libft/utils/ft_strchr.o\
				../build/libft/utils/ft_strdup.o\
				../build/libft/utils/ft_strlen.o\
				../build/libft/utils/ft_split.o\
				../build/libft/utils/ft_strjoin.o\
				../build/libft/utils/ft_atoi.o

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

files:
	@echo $(OBJS)
fclean: clean
	rm -rf $(NAME)
	rm -rf $(OBJDIR)/libft

re: fclean all
	
$(OBJDIR)/libft/%.o: src/%.c
	mkdir -p $(dir $@)
	gcc $<  -I$(INCDIR) $(FLAGS) -c -o $@