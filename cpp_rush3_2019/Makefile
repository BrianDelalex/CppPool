CC		:= g++

BINARY	:=	binary

BUILD_SUBDIR := $(addsuffix /*.o, $(addprefix src/,	modules/build	\
									gui/build		\
									text/build		\
									sync/build		\
									build))

LDFLAGS	:=	-lsfml-graphics 		\
			-lsfml-system 			\
			-lsfml-window 			\
			-lncurses

CFLAGSDEBUG	:= -D DEBUG -g3

RM		:=	rm -rf

OBJ 	= 	$(wildcard $(BUILD_SUBDIR))

.PHONY: re fclean run disassemble debug clean

all:	subDirectoriesBuild	 $(OBJ)

link:	$(BINARY)

disassemble: $(BINARY)
	@objdump --no-show-raw-insn -d -Mintel $(BINARY) | source-highlight -s asm -f esc256 | less -eRiMX

debug ?= 0
ifeq ($(debug), 1)
    CFLAGS += -D DEBUG
endif

re:	subDirectoriesFClean all

subDirectoriesBuild:
	@make -C src/modules -s --no-print-directory
	@make -C src/gui     -s --no-print-directory
	@make -C src/text    -s --no-print-directory
	@make -C src/sync    -s --no-print-directory
	@make -C src/		 -s --no-print-directory

subDirectoriesClean:
	@make clean -C src/modules --no-print-directory
	@make clean -C src/gui     --no-print-directory
	@make clean -C src/text    --no-print-directory
	@make clean -C src/sync    --no-print-directory
	@make clean -C src/		   --no-print-directory

subDirectoriesFClean:
	@make fclean -C src/modules --no-print-directory
	@make fclean -C src/gui     --no-print-directory
	@make fclean -C src/text    --no-print-directory
	@make fclean -C src/sync    --no-print-directory
	@make fclean -C src/		--no-print-directory

modulesBuild:
	@make -C src/modules -s --no-print-directory
guiBuild:
	@make -C src/gui     -s --no-print-directory
textBuild:
	@make -C src/text    -s --no-print-directory
syncBuild:
	@make -C src/sync    -s --no-print-directory
rootBuild:
	@make -C src/		 -s --no-print-directory

$(BINARY): $(OBJ)
	@$(CC) -o $(BINARY) $(OBJ) $(LDFLAGS)
	@-echo -e " LINKED      $@"

clean:	subDirectoriesClean

fclean:	subDirectoriesFClean
	@$(RM) $(BINARY) vgcore.*

run:
	@./$(BINARY)
