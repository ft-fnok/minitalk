# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 18:31:50 by nlalleik          #+#    #+#              #
#    Updated: 2021/12/17 23:07:06 by nlalleik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS =	 	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_itoa.c \
			ft_strtrim.c \
			ft_split.c \
			ft_strmapi.c \
			ft_striteri.c

BONFUNC =	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstlast.c \
			ft_lstsize.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

#OBJS = $(SRCS:c=o)

OBJS = $(subst .c,.o,$(SRCS))

BONOBJS = 	$(BONFUNC:c=o)

NAME =		libft.a

all: $(NAME)

# %.o:%.c
# 	$(CC) -c $(CFLAGS) $(SRCS)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(BONOBJS)
#	$(CC) -c $(CFLAGS) $(SRCS) $(BONFUNC)
	ar rcs $(NAME) $(BONOBJS)

clean: 
	@rm -f $(OBJS) $(BONOBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out

re: fclean all

.PHONY:    all    clean    fclean    re bonus