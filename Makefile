NAME=push_swap
HEADERS=push_swap.h \
		utils/utils.h \
		stack/stack.h
SRC=$(wildcard *.c) \
	$(wildcard utils/*.c) \
	$(wildcard stack/*.c)
OBJ=$(SRC:.c=.o)
FLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling..."
	@cc $(FLAGS) $(OBJ) -o $(NAME)
	@echo "Done!"

%.o: %.c $(HEADERS)
	@cc $(FLAGS) -c $< -o $@

clean:
	@echo "Cleaning..."
	@rm -f $(OBJ)
	@echo "Done!"

fclean: clean
	@echo "Cleaning..."
	@rm -f $(NAME)
	@echo "Done!"

re: fclean all
