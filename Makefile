# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhaque <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/20 12:54:49 by rhaque            #+#    #+#              #
#    Updated: 2017/09/26 18:51:46 by rhaque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c position.c check.c grid.c fillit.c shape.c usage.c

OBJ = $(SRC:.c=.o)

SRC_PATH = libft/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

LIBFT =	./libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT)
	gcc $(FLAGS) -I libft/ -c $(SRC)
	gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C ./libft/

clean:
	rm -f $(OBJ)
	rm -rf *.gch *.a
	make clean -C ./libft/

fclean: clean
	rm -f $(NAME)
	rm -rf *.gch *.a
	make fclean -C ./libft/

re: fclean all

.PHONY : all, re, clean, flcean
