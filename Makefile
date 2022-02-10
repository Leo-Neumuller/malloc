##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	malloc.c \
		free.c \

CXX =		gcc
CXXFLAGS =	-shared -W -Wall -Wextra -Werror -fPIC -I.
LDFLAGS =
NAME =		libmy_malloc.so
CFLAGS=-g

OBJ =		$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

valgrind:
	$(CXX) -o $(NAME) $(SRC) $(CXXFLAGS) -g


.PHONY: all clean fclean re valgrind