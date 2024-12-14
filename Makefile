# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 14:44:00 by cgrasser          #+#    #+#              #
#    Updated: 2024/12/14 17:28:44 by cgrasser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_CHECKER = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

SRC_DIR = src/
COMMON_DIR = common/
CHECKER_DIR = bonus/
INC_DIR = include/
OBJ_DIR = build/

SRC = push_swap.c \
	  little_sort.c \
	  sort.c \
	  optimal_sort.c \
	  execute_moves.c

CHECKER = checker.c \

COMMON = rotate.c \
		 rrotate.c \
		 push.c \
		 swap.c \
		 parse.c \
		 parse_utils.c \
		 init_list.c

BOLD = \033[1m
GREEN = \033[32m
YELLOW = \033[93m
RESET = \033[0m

CHECKER_OBJS = $(CHECKER:%.c=$(OBJ_DIR)/%.o)
COMMON_OBJS = $(COMMON:%.c=$(OBJ_DIR)/%.o)
OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)%.o: $(CHECKER_DIR)%.c
	@$(CC) $(CFLAGS) -I$(LIBFT_PATH)/include -I./include -c $< -o $@

$(OBJ_DIR)%.o: $(COMMON_DIR)%.c
	@$(CC) $(CFLAGS) -I$(LIBFT_PATH)/include -I./include -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -I$(LIBFT_PATH)/include -I./include -c $< -o $@

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

bonus: $(NAME_CHECKER)
	
$(NAME_CHECKER): $(LIBFT) $(OBJ_DIR) $(COMMON_OBJS) $(CHECKER_OBJS)
	@$(CC) $(COMMON_OBJS) $(CHECKER_OBJS) $(LIBFT) -o $(NAME_CHECKER)
	@echo "$(YELLOW) ➥ $(RESET)$(BOLD) $(NAME_CHECKER) $(GREEN)✔$(RESET)"

$(NAME): $(LIBFT) $(OBJ_DIR) $(COMMON_OBJS) $(OBJS)
	@$(CC) $(COMMON_OBJS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(YELLOW) ➥ $(RESET)$(BOLD) $(NAME) $(GREEN)✔$(RESET)"

$(LIBFT):
	@make -s -C $(LIBFT_PATH)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(BOLD) libft $(YELLOW)⮯ $(RESET)"
	@make -s -C $(LIBFT_PATH) clean
	@echo "$(BOLD) $(NAME) $(YELLOW)⮯ $(RESET)"
	@echo "$(YELLOW) ➥ $(RESET)$(BOLD)Cleaned all object files ! $(GREEN)✔$(RESET)\n"
	@$(RM) $(OBJ_DIR)

fclean:
	@echo "$(BOLD) libft $(YELLOW)⮯ $(RESET)"
	@make -s -C $(LIBFT_PATH) fclean
	@echo "$(BOLD) $(NAME) $(YELLOW)⮯ $(RESET)"
	@$(RM) $(OBJ_DIR)
	@echo "$(YELLOW) ➥ $(RESET)$(BOLD)Cleaned all object files ! $(GREEN)✔$(RESET)"
	@$(RM) $(NAME)
	@$(RM) $(NAME_CHECKER)
	@echo "$(YELLOW) ➥ $(RESET)$(BOLD)Cleaned $(NAME)/$(NAME_CHECKER) ! $(GREEN)✔$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus libft

