##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	:=	g++ -g3 #-coverage

NAME	:=	my_cat

LDFLAGS	:=	-g

CFLAGS	:=	-I./include/ -g -Wall -Wextra -Werror

RM	:=	rm -rf

SRC := $(wildcard *.cpp **/*.cpp)

OBJ := 	$(patsubst src/%.cpp, build/%.o, $(SRC))

.PHONY: all clean fclean link

all: $(NAME)

re:	fclean all

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

fclean:
	$(RM) build $(NAME) vgcore.*
build/%.o: src/%.cpp
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -c $< -o $@
