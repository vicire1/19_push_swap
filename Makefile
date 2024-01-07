# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 15:19:03 by vdecleir          #+#    #+#              #
#    Updated: 2024/01/06 20:16:37 by vdecleir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

SRCS =	srcs/main.c\
		srcs/utils.c\

OBJ_DIR = objets

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

LIBFT = libft.a

LIBFT_PATH = ./libft

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -o $(NAME) $(LIBFT)
	@echo "\n\033[1;32mCompilation complete.\033[0m"

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)
	mv $(LIBFT_PATH)/$(LIBFT) .

clean:
	$(MAKE) clean -C $(LIBFT_PATH)
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re