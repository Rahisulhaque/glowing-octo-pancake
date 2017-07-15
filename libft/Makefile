# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcornea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/22 18:28:58 by alcornea          #+#    #+#              #
#    Updated: 2017/02/26 19:22:34 by aabdrash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a


SRC = ft_memset.c ft_bzero.c ft_memalloc.c ft_memdel.c \
ft_strlen.c ft_strnew.c ft_strdel.c \
ft_isalpha.c ft_isdigit.c ft_strsub.c ft_strsplit.c \
ft_putchar.c ft_putstr.c ft_putendl.c ft_sqrt.c


OBJ = $(SRC:.c=.o)

HEADER = libft.h

CFLAGS = -c -Wall -Wextra -Werror -O3

all:	$(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) $(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME) && rm -rf libft/*.gch libft/libft.a

re: fclean all

