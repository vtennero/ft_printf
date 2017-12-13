# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtennero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/17 15:16:05 by vtennero          #+#    #+#              #
#    Updated: 2017/12/13 19:40:22 by vtennero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dummy_test

FLAGS =# -Wall -Werror -Wextra

LIBFT_DIR = libft
LIBFT_NAME = libft.a

LIBFT = $(patsubst %, $(LIBFT_DIR)/%,$(LIBFT_NAME))

OBJ =  main.o

SRC =  main.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(LIBFT)
	@ gcc $(FLAGS) -c $(SRC) ft_printf.h
	@ gcc $(FLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_DIR) -lft

$(LIBFT):
	@ make -C $(LIBFT_DIR)

clean:
	@ /bin/rm -f $(OBJ)
	@ make clean -C $(LIBFT_DIR)

fclean: clean
	@ /bin/rm -f $(NAME)
	@ make fclean -C $(LIBFT_DIR)

re: fclean all
