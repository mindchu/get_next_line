CC = cc
C_FLAGS = -Wall -Wextra -Werror

LIBC = ar rcs

SOURCE_PATH = ./
INCLUDE_PATH = ./

CFILES =	get_next_line_bonus.c get_next_line_utils_bonus.c

NAME = gnl.a
SOURCES := $(addprefix $(SOURCE_PATH), $(CFILES))
OBJS = $(SOURCES:.c=.o)

all: $(NAME)

%.o: %.c get_next_line_bonus.h Makefile
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "Compiling: $<\n"
	
$(NAME): $(OBJS)
	@echo "Packing GNL..."
	@$(LIBC) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(OBJBS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus