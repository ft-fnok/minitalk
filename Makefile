# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 16:09:34 by nlalleik          #+#    #+#              #
#    Updated: 2022/10/31 16:21:15 by nlalleik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := 		gcc

CFLAGS :=	-Wall -Werror -Wextra

PRINTF 	:=	./printf/libftprintf.a

LIBFT 	:=	./libft/libft.a

SRC_S 	:=	server.c \
			server-functions.c\

SRC_C	:=	client.c \

NAME 	= minitalk

SERVER	= server

CLIENT	= client

OBJ_S	= $(subst .c,.o,$(SRC_S))

OBJ_C	= $(subst .c,.o,$(SRC_C))

all: $(NAME) 

$(NAME): server client

server: $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_S) $(PRINTF) $(LIBFT) -o $(SERVER)

client: $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_C) $(PRINTF) $(LIBFT) -o $(CLIENT)

$(NAME): $(SERVER) $(CLIENT)
#	@ar rcs $(NAME) $(OBJS)
	@rm -f $(OBJ_S)
	@rm -f $(OBJ_C)

#	@rm -f $(NAME)

$(PRINTF):
	@make -C ./printf
	@rm -f $(OBJS)
#	@rm -f $(NAME)

$(LIBFT):
	@make -C ./libft
	@rm -f $(OBJS)
#	@rm -f $(NAME)
		 
clean: 
	@rm -f $(OBJ_S)
	@rm -f $(OBJ_C)
	@make clean -C ./printf
	@make clean -C ./libft

fclean: clean
	@rm -f $(SERVER)
	@rm -f $(CLIENT)
	@rm -f a.out
	@make fclean -C ./printf
	@make fclean -C ./libft

re: fclean all

.PHONY:    all    clean    fclean    re bonus