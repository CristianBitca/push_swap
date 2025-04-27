# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbitca <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 20:41:43 by cbitca            #+#    #+#              #
#    Updated: 2025/04/25 20:41:45 by cbitca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CC      = cc
# CFLAGS  = -Wall -Wextra -Werror 
CFLAGS  = -Wall -Wextra -Werror -fsanitize=address -g3 -O0


SRC_DIR     = src
INC_DIR     = include
LIB_DIR     = lib
LIBFT_DIR   = $(LIB_DIR)/libft


LIBFT_A     = $(LIBFT_DIR)/libft.a
LIBFT_LIB   = -L$(LIBFT_DIR) -lft


SRCS    = $(shell find $(SRC_DIR) -name "*.c")
OBJS    = $(SRCS:.c=.o)


NAME    = push_swap


all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	@echo "Compiling libft..."
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) -I$(INC_DIR) -I$(LIBFT_DIR) $(LIBFT_LIB) -o $(NAME)


clean:
	@echo "Cleaning object files..."
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean


fclean: clean
	@echo "Cleaning executable and libft.a..."
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean


re: fclean all


run: all
	./$(NAME) maps/test.ber

.PHONY: all clean fclean re run
