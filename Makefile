

NAME = fillit

SRC = main.c\
	  position.c\
	  check.c\
	  grid.c\
	  fillit.c\
	  shape.c\
	  usage.c\

OBJ = $(SRC:.c=.o)

//SRC_PATH = libft/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

//INC = -I includes

LIBFT =	./libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
		$(CC) $(FLAGS) -c $(SRC_POS)

$(LIBFT):
		make -C ./libft/

clean:
		rm -f $(OBJ) && rm -rf *.gch *.a
			make clean -C ./libft/

fclean: clean
		rm -f $(NAME) && rm -rf *.gch *.a
			make fclean -C ./libft/ && rm -rf libft/*.o libft/*.gch libft/libft.a

re: fclean all

.PHONY : all, re, clean, flcean
