# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykhadiri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 12:12:16 by ykhadiri          #+#    #+#              #
#    Updated: 2022/01/15 12:12:20 by ykhadiri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast
RM = rm -f

SRC = ft_draw.c \
	main.c \
	cards.c \
	used_functions.c \
	ft_calc.c \
	moves.c \

OBJ = $(SRC:.c=.o)

%.o: %.c fractol.h
	CC $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all : $(NAME)

bonus : all

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re: fclean all