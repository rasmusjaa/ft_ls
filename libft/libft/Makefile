# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 17:57:45 by rjaakonm          #+#    #+#              #
#    Updated: 2019/12/17 13:34:11 by rjaakonm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRCS =	srcs/ft_lstiter.c \
		srcs/ft_putstr.c \
		srcs/ft_strmapi.c \
		srcs/ft_atoi.c \
		srcs/ft_lstmap.c \
		srcs/ft_putstr_fd.c \
		srcs/ft_strncat.c \
		srcs/ft_bzero.c \
		srcs/ft_lstnew.c \
		srcs/ft_str_rev.c \
		srcs/ft_strncmp.c \
		srcs/ft_char_swap.c \
		srcs/ft_memalloc.c \
		srcs/ft_strcat.c \
		srcs/ft_strncpy.c \
		srcs/ft_count_words.c \
		srcs/ft_memccpy.c \
		srcs/ft_strchr.c \
		srcs/ft_strnequ.c \
		srcs/ft_int_numbercount.c \
		srcs/ft_memchr.c \
		srcs/ft_strclr.c \
		srcs/ft_strnew.c \
		srcs/ft_int_swap.c \
		srcs/ft_memcmp.c \
		srcs/ft_strcmp.c \
		srcs/ft_strnstr.c \
		srcs/ft_isalnum.c \
		srcs/ft_memcpy.c \
		srcs/ft_strcpy.c \
		srcs/ft_strrchr.c \
		srcs/ft_isalpha.c \
		srcs/ft_memdel.c \
		srcs/ft_strdel.c \
		srcs/ft_strsplit.c \
		srcs/ft_isascii.c \
		srcs/ft_memmove.c \
		srcs/ft_strdup.c \
		srcs/ft_strstr.c \
		srcs/ft_isdigit.c \
		srcs/ft_memset.c \
		srcs/ft_strequ.c \
		srcs/ft_strsub.c \
		srcs/ft_isprint.c \
		srcs/ft_putchar.c \
		srcs/ft_striter.c \
		srcs/ft_strtrim.c \
		srcs/ft_itoa.c \
		srcs/ft_putchar_fd.c \
		srcs/ft_striteri.c \
		srcs/ft_tolower.c \
		srcs/ft_len_itoc.c \
		srcs/ft_putendl.c \
		srcs/ft_strjoin.c \
		srcs/ft_toupper.c \
		srcs/ft_lstadd.c \
		srcs/ft_putendl_fd.c \
		srcs/ft_strlcat.c \
		srcs/ft_lstdel.c \
		srcs/ft_putnbr.c \
		srcs/ft_strlen.c \
		srcs/ft_lstdelone.c \
		srcs/ft_putnbr_fd.c \
		srcs/ft_strmap.c \
		srcs/ft_get_next_line.c \
		srcs/ft_pow.c \
		srcs/ft_strnew_c.c \
		srcs/ft_base_ltoa.c \
		srcs/ft_base_ultoa.c \
		srcs/ft_longlong_numbercount.c \
		srcs/ft_ulonglong_numbercount.c \
		srcs/ft_trim_n_first.c

OBJS = $(SRCS:.c=.o)

INCL = incl/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -I $(INCL) -c $(SRCS)
	@ar rc $(NAME) $(notdir $(OBJS))
	ranlib $(NAME)

clean:
	@rm -f $(notdir $(OBJS))

fclean: clean
	@rm -f $(NAME)

re: fclean all
