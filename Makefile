# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 15:19:03 by vdecleir          #+#    #+#              #
#    Updated: 2024/02/08 13:23:02 by vdecleir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
GREEN_BOLD = \033[1;32m
ORANGE = \033[0;38;5;214m
YELLOW = \033[0;33m
CLOSE = \033[0m

NAME = push_swap

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

SRCS =	srcs/main.c\
		srcs/arg_check.c\
		srcs/utils.c\
		srcs/index_in_stack.c\
		srcs/push.c\
		srcs/rev_rotate.c\
		srcs/rotate.c\
		srcs/swap.c\
		srcs/algos.c\
		srcs/utils_algo.c

OBJ_DIR = objets

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

LIBFT = libft.a

LIBFT_PATH = ./libft

LIBFT_FLAG = $(LIBFT_PATH)/.libcompiled

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT_FLAG) $(NAME)

$(NAME): $(OBJS)
	@echo "$(ORANGE)Compiling push_swap...$(CLOSE)"
	@$(CC) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)
	@echo "$(GREEN_BOLD)The push_swap executable is ready.$(CLOSE)"

$(LIBFT_FLAG):
	@echo "$(ORANGE)Compiling Libft...$(CLOSE)"
	@make -s -C $(LIBFT_PATH)
	@echo "$(GREEN)Libft ready.$(CLOSE)"
	@touch $(LIBFT_FLAG)

clean:
	@$(MAKE) clean -s -C $(LIBFT_PATH)
	@$(RM) $(OBJ_DIR)
	@echo "$(YELLOW)Objects correctly deleted.$(CLOSE)"

fclean: clean
	@$(RM) $(NAME) $(LIBFT_PATH)/$(LIBFT) $(LIBFT_FLAG)
	@echo "$(YELLOW)Executable file(s) correctly deleted.$(CLOSE)"

re: fclean all

.PHONY: all clean fclean re