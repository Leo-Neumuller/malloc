##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	malloc.c \
		free.c \
		alloc_memory.c \
		calloc.c \
		handle_new_block.c \

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

test: re
	mv libmy_malloc.so ./tests/
	tests/tester.bash


.PHONY: all clean fclean re test