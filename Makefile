# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amakhiny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 13:52:27 by amakhiny          #+#    #+#              #
#    Updated: 2017/10/24 13:53:44 by amakhiny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
GC = gcc
CFLAGS = -c -Wall -Wextra -Werror -I /includes/*.h
SOURCE = *.c
OBJ = $(SOURCE:.c=.o)
	SRC = $(patsubst %, srcs/%, $(SOURCE))

all: $(NAME)

$(NAME):
		$(GC) $(CFLAGS) $(SRC)
		ar rc $(NAME) $(OBJ)
		gcc main.c -L. -lft -o tst

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all