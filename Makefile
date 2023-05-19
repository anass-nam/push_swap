NAME=push_swap
HEADER=$(NAME:=.h)
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
FLAGS=-g

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling..."
	@cc $(FLAGS) $(OBJ) -lft -o $(NAME)
	@echo "Done!"

%.o: %.c $(HEADER)
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
