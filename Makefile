# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 14:44:00 by cgrasser          #+#    #+#              #
#    Updated: 2024/12/01 17:04:36 by cgrasser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC_DIR = src/
INC_DIR = include/
OBJ_DIR = build/

SRC = main.c \
	  list.c \
	  parse.c \
	  push.c \
	  radix_sort.c \
	  rotate.c \
	  rrotate.c \
	  swap.c \
	  utils.c

BOLD = \033[1m
GREEN = \033[32m
YELLOW = \033[93m
RESET = \033[0m

OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -I$(LIBFT_PATH)/include -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(YELLOW) ➥ $(RESET)$(BOLD) push_swap $(GREEN)✔$(RESET)"

$(LIBFT):
	@make -s -C $(LIBFT_PATH) sub

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(BOLD) Submodule libft $(YELLOW)⮯ $(RESET)"
	@make -s -C $(LIBFT_PATH) clean
	@echo "$(BOLD) Push_swap $(YELLOW)⮯ $(RESET)"
	@echo "$(BOLD) ⋅ Cleaned all object files ! $(GREEN)✔$(RESET)\n"
	@$(RM) $(OBJ_DIR)

fclean:
	@echo "$(BOLD) Submodule libft $(YELLOW)⮯ $(RESET)"
	@make -s -C $(LIBFT_PATH) fclean
	@echo "$(BOLD) Push_swap $(YELLOW)⮯ $(RESET)"
	@$(RM) $(OBJ_DIR)
	@echo "$(BOLD) ⋅ Cleaned all object files ! $(GREEN)✔$(RESET)"
	@$(RM) $(NAME)
	@echo "$(BOLD) ⋅ Cleaned push_swap.exe ! $(GREEN)✔$(RESET)"

re: fclean all

.PHONY: all clean fclean re libft

