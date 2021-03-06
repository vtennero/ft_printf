# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtennero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/17 15:16:05 by vtennero          #+#    #+#              #
#    Updated: 2018/02/11 11:18:10 by vtennero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SRC =  ft_printf.c \
	   ft_format.c \
	   ft_create_params.c \
	   ft_set_params.c \
	   ft_override_params.c \
	   ft_override_length.c \
	   ft_prop_cast.c \
	   ft_is_s.c \
	   ft_is_d.c \
	   ft_is_c.c \
	   ft_is_u.c \
	   ft_is_o.c \
	   ft_is_p.c \
	   ft_is_x.c \
	   ft_is_cap_s.c \
	   ft_is_s_perc.c \
	   ft_unicode.c \
	   ft_precision.c \
	   ft_width.c \
	   ft_prepend_or_append.c \
	   ft_left_or_right.c \
	   ft_print_buffer.c \

LSRC = ft_memcmp.c \
	  ft_strclr.c \
	  ft_strnequ.c \
	  ft_atoi.c \
	  ft_memcpy.c \
	  ft_strcmp.c \
	  ft_strnew.c \
	  ft_bzero.c \
	  ft_memdel.c \
	  ft_strcpy.c \
	  ft_strnstr.c \
	  ft_isalnum.c \
	  ft_memmove.c \
	  ft_strdel.c \
	  ft_strrchr.c \
	  ft_isalpha.c \
	  ft_memset.c \
	  ft_strdup.c \
	  ft_strsplit.c \
	  ft_isascii.c \
	  ft_putchar.c \
	  ft_strequ.c \
	  ft_isdigit.c \
	  ft_putchar_fd.c \
	  ft_striter.c \
	  ft_isprint.c \
	  ft_putendl.c \
	  ft_striteri.c \
	  ft_strstr.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_strlcat.c \
	  ft_strtrim.c \
	  ft_strjoin.c \
	  ft_strsub.c \
	  ft_putnbr_fd.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_strmapi.c \
	  ft_tolower.c \
	  ft_memalloc.c \
	  ft_strncat.c \
	  ft_toupper.c \
	  ft_memccpy.c \
	  ft_strcat.c \
	  ft_strncmp.c \
	  ft_memchr.c \
	  ft_strjoin_clr.c \
	  ft_strchr.c \
	  ft_strncpy.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_char_pos.c \
	  ft_lstnew.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstmap.c \
	  ft_strndup.c \
	  ft_abs.c \
	  ft_abs_ll.c \
	  ft_max.c \
	  ft_itoa.c \
	  ft_ltoa.c \
	  ft_lutoa.c \
	  ft_lltoa.c \
	  ft_llutoa.c \
	  ft_itoa_base.c \
	  ft_ltoa_base.c \
	  ft_lutoa_base.c \
	  ft_lltoa_base.c \
	  ft_llutoa_base.c \
	  ft_intlen.c \
	  ft_longlen.c \
	  ft_ulonglen.c \
	  ft_llonglen.c \
	  ft_ullonglen.c \
	  ft_wcharlen.c \
	  ft_wstrlen.c \
	  ft_eq_char.c

PLSRC = $(addprefix libft/, $(LSRC))

PSRC = $(addprefix src/, $(SRC))

OBJ =  $(SRC:.c=.o) $(LSRC:.c=.o)

all: $(NAME)

$(NAME):
	@ gcc -c $(PLSRC) $(FLAGS) -I libft/
	@ gcc -c $(PSRC) $(FLAGS) -I src/
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)

clean:
	@ /bin/rm -f $(OBJ)

fclean:
	@ make clean
	@ /bin/rm -f $(NAME)
	@ /bin/rm -f $(NAME)

re:
	@ make fclean
	@ make all

.PHONY: all clean fclean re
