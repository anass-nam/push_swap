# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anammal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 02:45:24 by anammal           #+#    #+#              #
#    Updated: 2023/06/11 02:45:28 by anammal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME=push_swap
BNAME=checker
HEADER=src/$(NAME:=.h)
BHEADER=bonus/$(BNAME:=.h)
SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
BSRC=$(wildcard bonus/*.c)
BOBJ=$(BSRC:.c=.o)
CC=cc
CFLAGS=-Werror -Wall -Wextra
LFTDIR=libft
LIBFT=$(LFTDIR:=.a)
LFT= -I$(LFTDIR) -L$(LFTDIR) -lft

R=\033[1;31m
G=\033[1;32m
Y=\033[1;33m
NC=\033[1;0m
CLR=\033[2J\033[u

all: $(NAME)
	@echo "$(CLR)$(G)The compilation of $(NAME) was successful.$(NC)"


$(NAME): $(LIBFT) $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) $(LFT) -o $@

bonus: $(LIBFT) $(BOBJ) $(BHEADER)
	@$(CC) $(CFLAGS) $(BOBJ) $(LFT) -o $(BNAME)

$(LIBFT):
	@make -C $(LFTDIR)
	@make bonus -C $(LFTDIR)

%.o: %.c
	@echo "$(CLR)$(Y) Compiling: $< ... Done$(NC)!"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LFTDIR)
	@echo "$(CLR)$(R)The object file has been cleaned.$(NC)"
	@rm -f $(OBJ) $(BOBJ)

fclean: clean
	@make fclean -C $(LFTDIR)
	@echo "$(CLR)$(R)push_swap has been completely cleaned.$(NC)"
	@rm -f $(NAME) $(BNAME)

.PHONY: all bonus clean fclean re
