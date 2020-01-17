# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 15:06:49 by rjaakonm          #+#    #+#              #
#    Updated: 2019/12/17 15:07:12 by rjaakonm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	printf/srcs/ft_printf.c \
		printf/srcs/ft_dprintf.c \
		printf/srcs/ft_rprintf.c \
		printf/srcs/arg_funcs.c \
		printf/srcs/arg_funcs2.c \
		printf/srcs/arg_funcs3.c \
		printf/srcs/list_funcs.c \
		printf/srcs/help_funcs.c \
		printf/srcs/help_funcs2.c \
		printf/srcs/help_funcs3.c \
		printf/srcs/check_funcs.c \
		printf/srcs/handle_floats.c \
		printf/srcs/width.c \
		printf/srcs/flags.c \
		printf/srcs/colors.c

LFTSRC = libft/libft.a

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

INCL = -I printf/incl -I libft/incl

.PHONY: all clean fclean re run run2

all: $(NAME)

$(NAME): libftmake
	@cp libft/libft.a $(NAME)
	@gcc $(FLAGS) $(INCL) -c $(SRCS)
	@ar rc $(NAME) $(notdir $(OBJS))
	ranlib $(NAME)

libftmake:
	@make -C libft

clean:
	@rm -f $(notdir $(OBJS))
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all

run: re
	gcc $(FLAGS) main.c $(NAME)
	./a.out

run2: re
	clang main.c $(NAME)
	./a.out
