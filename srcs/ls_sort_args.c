/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:08:15 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/29 15:40:29 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_arg_swap(char **av, int i)
{
	char			*tmp;

	tmp = av[i];
	av[i] = av[i + 1];
	av[i + 1] = tmp;
}

static int	ls_arg_modified(char **av, int i)
{
	struct stat		buf1;
	struct stat		buf2;

	if (lstat(av[i], &buf1) == -1 && lstat(av[i + 1], &buf2) == -1)
	{
		if (ft_strcmp(av[i], av[i + 1]) > 0)
		{
			ls_arg_swap(av, i);
			return (1);
		}
	}
	else if (lstat(av[i], &buf1) != -1 && lstat(av[i + 1], &buf2) == -1)
	{
		ls_arg_swap(av, i);
		return (1);
	}
	else if (buf1.st_mtime < buf2.st_mtime)
	{
		ls_arg_swap(av, i);
		return (1);
	}
	return (0);
}

static int	ls_arg_az(char **av, int i)
{
	if (ft_strcmp(av[i], av[i + 1]) > 0)
	{
		ls_arg_swap(av, i);
		return (1);
	}
	return (0);
}

void		ls_sort_args(int ac, char **av, int i, t_ls *data)
{
	int				start;

	start = i;
	if (data->t_flag == 0)
		while (i + 1 < ac)
		{
			if (ls_arg_az(av, i) == 1)
				i = start - 1;
			i++;
		}
	else
		while (i + 1 < ac)
		{
			if (ls_arg_modified(av, i) == 1)
				i = start - 1;
			i++;
		}
}
