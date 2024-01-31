# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 15:19:03 by vdecleir          #+#    #+#              #
#    Updated: 2024/01/30 17:40:36 by vdecleir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@echo "\n\033[0;38;5;214mCompiling push_swap...\033[0m"
	$(CC) $(OBJS) -o $(NAME) $(LIBFT_PATH)/$(LIBFT)
	@echo "\n\033[1;32mThe push_swap executable is ready.\033[0m"

$(LIBFT):
	@echo "\n\033[0;38;5;214mCompiling Libft...\033[0m"
	make -s -C $(LIBFT_PATH)
	@echo "\n\033[0;32mLibft ready.\033[0m"

clean:
	make clean -s -C $(LIBFT_PATH)
	$(RM) $(OBJ_DIR)
	@echo "\n\033[0;33mObjects correctly deleted.\033[0m"

fclean: clean
	$(RM) $(NAME) $(LIBFT_PATH)/$(LIBFT)
	@echo "\n\033[0;33mExecutable file(s) correctly deleted.\033[0m"

re: fclean all

.PHONY: all clean fclean re