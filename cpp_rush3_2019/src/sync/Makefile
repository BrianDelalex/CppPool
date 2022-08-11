CC		:=	g++

BINARY	:=	binary

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

SRC_C   :=	$(wildcard *.cpp */*.cpp)

OBJ 	:= 	$(patsubst %.cpp, $(BUILDIR)/%.o, $(SRC_C))

.PHONY: all fclean run disassemble debug clean

all:	$(OBJ)

disassemble: $(BINARY)
	@objdump --no-show-raw-insn -d -Mintel $(BINARY) | source-highlight -s asm -f esc256 | less -eRiMX

debug ?= 0
ifeq ($(debug), 1)
    CFLAGS += -D DEBUG
endif

re:	fclean all

clean:
	@$(RM) $(BUILDIR)

fclean:
	@$(RM) $(BUILDIR) $(BINARY) vgcore.*

$(BUILDIR)/%.o: %.cpp
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@-echo -e "     CC      $@"

run:
	@./$(BINARY)
