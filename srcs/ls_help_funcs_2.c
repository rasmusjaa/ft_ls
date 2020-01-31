/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_help_funcs_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:20:29 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/31 14:13:27 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_init_layout(t_ls *data)
{
	data->col_width = 15;
	data->link_width = 1;
	data->user_width = 1;
	data->group_width = 1;
	data->byte_width = 1;
	data->col_count = 1;
	data->cur_col = 0;
	data->dir_contains = 0;
}

int			ls_if_longer(int current, char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i > current ? i : current);
}

int			ls_ends_in_slash(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == '/')
		return (0);
	return (1);
}

int			ls_arg_exists(int ac, char **av, int i, t_ls *data)
{
	struct stat		test;
	int				ret;

	ret = 0;
	while (i++ < ac - 1)
	{
		if (lstat(av[i], &test) == -1)
		{
			data->arg_missing++;
			ft_printf("./ft_ls: %s: No such file or directory\n", av[i]);
			ret = -1;
		}
	}
	return (ret);
}

void		ls_short_time(char *now, char *file)
{
	int		i;

	i = 0;
	if (ft_strncmp(&now[20], &file[20], 4))
	{
		while (file[i])
			i++;
		write(1, &file[4], i - 18);
		write(1, " ", 1);
		write(1, &file[20], 4);
	}
	else
	{
		while (file[i])
			i++;
		write(1, &file[4], i - 13);
	}
}
