CC		:=	g++

BUILDIR	:=	build

INCLUDE_DIR := $(addprefix -I../../inc/,	modules/	\
											gui/		\
											text/		\
											sync/		\
											/)

CFLAGS		:=	$(INCLUDE_DIR)		\
				-Wall 				\
				-Wextra 			\
				-Wuninitialized

LDFLAGS	:=	

CFLAGSDEBUG	:= -D DEBUG -g3

RM		:=	rm -rf

SRC_C   :=	$(wildcard *.cpp)

OBJ 	:= 	$(patsubst %.cpp, $(BUILDIR)/%.o, $(SRC_C))

.PHONY: all fclean run disassemble debug clean

all:	$(OBJ)

debug ?= 0
ifeq ($(debug), 1)
    CFLAGS += -D DEBUG
endif

re:	fclean all

clean:
	@$(RM) $(BUILDIR)

fclean:
	@$(RM) $(BUILDIR)

$(BUILDIR)/%.o: %.cpp
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@-echo -e "     CC      $@"

run:
	@./$(BINARY)
