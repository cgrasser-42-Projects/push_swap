# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 14:44:00 by cgrasser          #+#    #+#              #
#    Updated: 2024/11/28 16:15:12 by cgrasser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC_DIR = src/
INC_DIR = include/
OBJ_DIR = build/

SRC = main.c

BOLD = \033[1m
GREEN = \033[32m
RESET = \033[0m

BANNER = printf "\n ██████$(GREEN)╗$(RESET) ██$(GREEN)╗$(RESET)   ██$(GREEN)╗$(RESET)███████$(GREEN)╗$(RESET)██$(GREEN)╗$(RESET)  ██$(GREEN)╗$(RESET)        ███████$(GREEN)╗$(RESET)██$(GREEN)╗$(RESET)    ██$(GREEN)╗$(RESET) █████$(GREEN)╗$(RESET) ██████$(GREEN)╗$(RESET)     \
\n ██$(GREEN)╔══$(RESET)██$(GREEN)╗$(RESET)██$(GREEN)║$(RESET)   ██$(GREEN)║$(RESET)██$(GREEN)╔════╝$(RESET)██$(GREEN)║$(RESET)  ██$(GREEN)║$(RESET)        ██$(GREEN)╔════╝$(RESET)██$(GREEN)║$(RESET)    ██$(GREEN)║$(RESET)██$(GREEN)╔══$(RESET)██$(GREEN)╗$(RESET)██$(GREEN)╔══$(RESET)██$(GREEN)╗$(RESET)    \
\n ██████$(GREEN)╔╝$(RESET)██$(GREEN)║$(RESET)   ██$(GREEN)║$(RESET)███████$(GREEN)╗$(RESET)███████$(GREEN)║$(RESET)        ███████$(GREEN)╗$(RESET)██$(GREEN)║$(RESET) █$(GREEN)╗$(RESET) ██$(GREEN)║$(RESET)███████$(GREEN)║$(RESET)██████$(GREEN)╔╝$(RESET)    \
\n ██$(GREEN)╔═══╝$(RESET) ██$(GREEN)║$(RESET)   ██$(GREEN)║╚════$(RESET)██$(GREEN)║$(RESET)██$(GREEN)╔══$(RESET)██$(GREEN)║        ╚════$(RESET)██$(GREEN)║$(RESET)██$(GREEN)║$(RESET)███$(GREEN)╗$(RESET)██$(GREEN)║$(RESET)██$(GREEN)╔══$(RESET)██$(GREEN)║$(RESET)██$(GREEN)╔═══╝$(RESET)     \
\n ██$(GREEN)║     ╚$(RESET)██████$(GREEN)╔╝$(RESET)███████$(GREEN)║$(RESET)██$(GREEN)║$(RESET)  ██$(GREEN)║$(RESET)███████$(GREEN)╗$(RESET)███████$(GREEN)║╚$(RESET)███$(GREEN)╔$(RESET)███$(GREEN)╔╝$(RESET)██$(GREEN)║$(RESET)  ██$(GREEN)║$(RESET)██$(GREEN)║$(RESET)         \
\n $(GREEN)╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝$(RESET)         \n\n"

COMPILE_COUNT = 0

OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -I$(LIBFT_PATH)/include -c $< -o $@
	$(eval COMPILE_COUNT=$(shell echo $$(($(COMPILE_COUNT)+1))))
	@printf "$(GREEN)█$(RESET)"

all: banner $(NAME)

banner:
	@$(BANNER)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(BOLD)\n\n ⋅ $(COMPILE_COUNT) file compiled ! $(GREEN)✔$(RESET)\n"

$(LIBFT):
	@echo "\n$(BOLD) Compilation of the libft submodule : $(RESET)\n"
	@make -s -C $(LIBFT_PATH) sub

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(BOLD) Submodule libft : $(RESET)"
	@make -s -C $(LIBFT_PATH) clean
	@echo "$(BOLD) Push_swap : $(RESET)"
	@echo "\n$(BOLD) ⋅ Cleaned all object files ! $(GREEN)✔$(RESET)\n"
	@$(RM) $(OBJ_DIR)

fclean:
	@echo "$(BOLD) Submodule libft : $(RESET)"
	@make -s -C $(LIBFT_PATH) fclean
	@echo "$(BOLD) Push_swap : $(RESET)"
	@$(RM) $(OBJ_DIR)
	@echo "\n$(BOLD) ⋅ Cleaned all object files ! $(GREEN)✔$(RESET)\n"
	@$(RM) $(NAME)
	@echo "$(BOLD) ⋅ Cleaned ./push_swap ! $(GREEN)✔$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re libft

