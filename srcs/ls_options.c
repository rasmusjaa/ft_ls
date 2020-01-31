/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:42:08 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/29 18:07:49 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ls_check_char(char c, t_ls *data)
{
	if (c == 'l')
		data->l_flag = 1;
	else if (c == 'R')
		data->cr_flag = 1;
	else if (c == 'a')
		data->a_flag = 1;
	else if (c == 'r')
		data->r_flag = 1;
	else if (c == 't')
		data->t_flag = 1;
	else if (c == 'T')
		data->ct_flag = 1;
	else if (c == '\0')
		return (0);
	else
		return (1);
	return (0);
}

static void	ls_set_ls(t_ls *data)
{
	struct winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	data->term_w = w.ws_col;
	data->cur_col = 0;
	data->l_flag = 0;
	data->cr_flag = 0;
	data->a_flag = 0;
	data->r_flag = 0;
	data->t_flag = 0;
	data->ct_flag = 0;
	data->arg_files = 0;
	data->arg_dirs = 0;
	data->arg_missing = 0;
}

int			ls_options(int ac, char **av, t_ls *data)
{
	int				i;
	int				j;

	ls_set_ls(data);
	i = 1;
	while (i < ac && (av[i][0] == '-' && av[i][1]))
	{
		j = 1;
		while (av[i][j])
		{
			if (ls_check_char(av[i][j], data) != 0)
				ls_usage(data);
			j++;
		}
		i++;
	}
	return (ls_read(ac, av, i, data));
}
