##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	:=	gcc -g3 -std=gnu11  #-coverage

NAME	:=	z

LDFLAGS	:=	-g

CFLAGS	+=	-I./include/ -g -Wall -Wextra

RM	:=	rm -rf

SRC := z.c

OBJ := 	$(patsubst src/%.c, build/%.o, $(SRC))

.PHONY: all clean fclean link

all: $(NAME)

re:	fclean all

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

fclean:
	$(RM) build $(NAME) vgcore.*
build/%.o: src/%.c
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -c $< -o $@
