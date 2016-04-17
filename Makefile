#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/04 14:27:29 by rbaum             #+#    #+#              #
#    Updated: 2016/03/12 15:35:05 by rbaum            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: clean, fclean, re

CC = gcc

CFLAG = -Wall -Wextra -Werror -g

NAME = ./fdf

SRC = 	./srcs/draw.c\
		./srcs/ft_put_pixel.c\
		./srcs/main.c\

OBJ = $(subst srcs/,, $(SRC:.c=.o))

LIBFT = libft/

LIBFTEXE = $(LIBFT)libft.a

MLX = -lmlx -framework OpenGL -framework Appkit


all:    $(NAME)

$(NAME): $(OBJ) $(LIBFTEXE)

		@$(CC) $(CFLAG) -L $(LIBFT) -lft -o $(NAME)  $(OBJ) $(MLX)

$(OBJ): $(SRC)
		@$(CC) $(CFLAG) -I ./ -I  $(LIBFT)  -c $(SRC) 

$(LIBFTEXE): $(LIBFT)
		@make -k -s -C $(LIBFT)	

clean:	
		@rm -f  $(OBJ)
		@make -C $(LIBFT) clean

fclean: 
		@rm -f  $(OBJ)	
		@rm -f $(NAME)
		@make -C $(LIBFT) fclean

re:		fclean all

