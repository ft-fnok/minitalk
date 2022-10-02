# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 16:09:34 by nlalleik          #+#    #+#              #
#    Updated: 2022/10/02 16:15:58 by nlalleik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := 		gcc

CFLAGS :=	-Wall -Werror -Wextra

PRINTF 	:=	./lib/printf/libftprintf.a

LIBFT 	:=	./lib/libft/libft.a

SRC_S 	:=	server.c \

SRC_C	:=	client.c \

SERVER = server

CLIENT = client

OBJ_S = $(@subst .c,.o,$(SRC_S))

OBJ_C = $(@subst .c,.o,$(SRC_C))

all: $(SERVER) $(CLIENT) $(PRINTF) $(LIBFT)

# %.o:%.c
	$(CC) $(CFLAGS) $(SRC_S) $(PRINTF) $(LIBFT) -o $(SERVER)
	$(CC) $(CFLAGS) $(SRC_C) $(PRINTF) $(LIBFT) -o $(CLIENT)

$(NAME): $(OBJS)
#	@ar rcs $(NAME) $(OBJS)
	@rm -f $(OBJ_S)
	@rm -f $(OBJ_C)

#	@rm -f $(NAME)

#$(PRINTF):
#	@make -C ./ft_printf
#	@rm -f $(OBJS)
#	@rm -f $(NAME)

#$(LIBFT):
#	@make -C ./libft
#	@rm -f $(OBJS)
#	@rm -f $(NAME)
		 
clean: 
	@rm -f $(OBJS)
#	@make clean -C ./ft_printf
#	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out
#	@make fclean -C ./ft_printf
#	@make fclean -C ./libft

re: fclean all

.PHONY:    all    clean    fclean    re bonus