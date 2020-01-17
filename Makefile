# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 14:55:48 by rjaakonm          #+#    #+#              #
#    Updated: 2020/01/16 15:03:11 by rjaakonm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS =	srcs/main.c \

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

LIB = -L libft/ -lft

INCL = -I incl/ -I libft/libft/incl/ -I libft/printf/incl/

.PHONY: all clean fclean re run

all: $(NAME)

$(NAME): libftmake
	gcc $(FLAGS) $(INCL) $(SRCS) $(LIB) -o $(NAME)

libftmake:
	@make -C libft

clean:
#	@rm -f $(notdir $(OBJS))
#	@rm -f $(OBJS)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all

run:
	gcc $(FLAGS) $(INCL) $(SRCS) $(LIB) -o $(NAME)
	./ft_ls
