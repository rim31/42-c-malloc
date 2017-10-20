ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME	= libft_malloc_$(HOSTTYPE).so
FILES	= malloc.c
SRCS	= $(addprefix src/, $(FILES))
OBJS	= $(SRCS:src/%.c=.obj/%.o)
INC		= -I include -I libft/includes
FLAGS	= -Wall -Wextra -Werror
LIB		= -L libft -lft
CC		= gcc

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[96m                  by 🏀 seng\033[97m         "
	@echo "\033[91mCompiling 😇\033[97m"
		@make -C libft
		#@$(CC) $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB)
		@$(CC) -shared -o $(NAME) $(OBJS) $(LIB)
		@ln -s $(NAME) libft_malloc.so
		@echo "\033[90mDone 😎\033[97m"
.obj/%.o: src/%.c
	mkdir -p .obj
	@$(CC) -c $< -o $@ $(FLAGS) $(INC)

clean:
	@echo "\033[92mDeleting 💀\033[97m"
	@rm -rf .obj
	@make clean -C libft
	@echo "\033[96mClean done 😡\033[97m"

fclean: clean
	@echo "\033[92mDeleting 💀\033[97m"
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "\033[96mFclean Done 👿\033[97m"
	@rm -f libft_malloc.so libft_malloc_x86_64_Darwin.so

re: fclean all

.PHONY: all clean fclean re



















# CC    = gcc
# CFLAGS       =
# CFLAGS       =  -Wall -Wextra -Werror
#
#
# TARGET  = libft_malloc_$HOSTTYPE.so
# SOURCES = $(shell echo malloc.c main.c)
# HEADERS = $(shell echo include/malloc.h)
# OBJECTS = $(SOURCES:.c=.o)
#
#
#
# all: $(TARGET)
#
# $(TARGET): $(OBJECTS)
# 	    $(CC) $(CFLAGS)  -o $(TARGET) $(OBJECTS)
#
# clean:
# 	@rm -f $(OBJ)
#
# fclean: clean
# 	@rm -f $(NAME)
#
# re:	fclean all
#
# .PHONY: all clean fclean re
