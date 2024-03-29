# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarbieu <abarbieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 09:47:38 by abarbieu          #+#    #+#              #
#    Updated: 2023/08/10 09:14:45 by abarbieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c \
		parsing.c \
		fill_tab.c \
		case.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		algorithm.c \
		search_min_move.c \
		min_move_utils.c \
		search.c \
		sort_a.c \
		sort_b.c \
		sort_b_utils.c

OBJ = ${SRC:.c=.o}

LIBFT = Libft/libft.a

HEADER = push_swap.h

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

CC = gcc

REMOVE = rm -f

DEPENDS = make -C ./Libft 

COMPILE = gcc $(CFLAGS) -o $(NAME) -I./Libft -L./Libft -lft

# Colors
GREEN= \033[1;32m
RED= \033[1;31m
WHITE= \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		$(COMPILE) $(OBJ) $(LIBFT)

$(LIBFT):
	$(DEPENDS)
	
clean:
	@$(REMOVE) $(OBJ)
	@make -C ./Libft clean
	@echo "$(GREEN)All .o removed$(WHITE)"

fclean: clean
	@$(REMOVE) $(NAME)
	@$(REMOVE) Libft/libft.a
	@echo "$(GREEN)All .a removed$(WHITE)"

re: fclean all

.c.o : $(CC) -c $(CFLAGS) -I./Libft $< -o $@

norm:
	norminette -R CheckForbiddenSourceHeader $(SRC) $(HEADER)
	make -C ./Libft norm

.PHONY: all clean fclean re norm

#.SILENT: all clean fclean re norm