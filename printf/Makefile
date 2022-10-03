# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 18:31:50 by nlalleik          #+#    #+#              #
#    Updated: 2022/01/17 17:09:45 by nlalleik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS =	 	ft_bzero.c \
			ft_calloc.c \
			ft_strlen.c \
			ft_printf.c \
			ft_printf_case-helpers.c \
			ft_printf_cases-csdiu.c \
			ft_printf_cases-xXp.c \


#OBJS = $(SRCS:c=o)

OBJS = $(subst .c,.o,$(SRCS))

NAME =		libftprintf.a

all: $(NAME)

# %.o:%.c
# 	$(CC) -c $(CFLAGS) $(SRCS)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean: 
	@rm -f $(OBJS) 
fclean: clean
	@rm -f $(NAME)
	@rm -f a.out

re: fclean all

.PHONY:    all    clean    fclean    re bonus