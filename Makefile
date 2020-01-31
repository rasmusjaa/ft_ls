# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 14:55:48 by rjaakonm          #+#    #+#              #
#    Updated: 2020/01/31 14:17:26 by rjaakonm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS =	srcs/main.c \
		srcs/ls_arg_dirs.c \
		srcs/ls_arg_files.c \
		srcs/ls_bonus.c \
		srcs/ls_dir_funcs.c \
		srcs/ls_help_funcs.c \
		srcs/ls_help_funcs_2.c \
		srcs/ls_help_funcs_3.c \
		srcs/ls_l_flag.c \
		srcs/ls_options.c \
		srcs/ls_print.c \
		srcs/ls_print_rev.c \
		srcs/ls_recursive.c \
		srcs/ls_sort_args.c \
		srcs/ls_sort_list.c

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
