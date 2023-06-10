NAME=push_swap
HEADER=$(NAME:=.h)
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
CC=cc
CFLAGS=-Werror -Wall -Wextra
LFTDIR=libft
LIBFT=libft.a
LFT= -I./$(LFTDIR) -L./$(LFTDIR) -lft

R=\033[1;31m
G=\033[1;32m
Y=\033[1;33m
NC=\033[1;0m

all: $(NAME)
	@clear
	@echo "$(G)The compilation of $(NAME) was successful.$(NC)"

$(LIBFT):
	@make -C $(LFTDIR)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LFT) -o $@

%.o: %.c $(HEADER)
	@echo "$(Y) Compiling: $< ... Done$(NC)!"
	@$(CC) $(CFLAGS) -c $< -o $@
	@clear

clean:
	@make clean -C $(LFTDIR)
	@clear
	@echo "$(R)The object file has been cleaned.$(NC)"
	@rm -f $(OBJ)"

fclean: clean
	@make fclean -C $(LFTDIR)
	@clear
	@echo "$(R)push_swap has been completely cleaned.$(NC)"
	@rm -f $(NAME)

.PHONY: all bonus clean fclean re