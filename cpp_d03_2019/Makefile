##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	:=	gcc #-coverage

NAME	:=	libstring.a

LDFLAGS	:=	-g

CFLAGS	:=	-std=gnu11 -Wall -Wextra

RM	:=	rm -rf

SRC :=	string.c	\
		string2.c	\
		string3.c	\
		string4.c	\
		string5.c	\
		string6.c	\

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean link

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f *.o

re:	fclean all