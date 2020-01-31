/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_arg_dirs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:12:49 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/31 15:53:26 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ls_total_dir(char *str)
{
	DIR				*dir;
	struct stat		buf;
	struct dirent	*sd;
	int				total;
	char			path[2048];

	total = 0;
	dir = opendir(str);
	while ((sd = readdir(dir)) != NULL)
	{
		ft_strcpy(path, str);
		if (ls_ends_in_slash(path))
			ft_strcat(path, "/");
		ft_strcat(path, sd->d_name);
		lstat(path, &buf);
		total += buf.st_blocks;
	}
	closedir(dir);
	return (total);
}

static int	ls_arg_dir_r_loop(int ac, char **av, int i, t_ls *data)
{
	struct stat		buf;
	int				ret;

	ret = 0;
	ac = ac + 1;
	while (ac-- > i)
	{
		if (lstat(av[ac], &buf) != -1 && S_ISDIR(buf.st_mode) != 0)
		{
			if (data->arg_files > 0 || data->arg_missing > 0
					|| data->arg_dirs > 0)
				ft_printf("\n%s:\n", av[ac]);
			else if (ac != i + 1)
				ft_printf("%s:\n", av[ac]);
			data->arg_dirs++;
			if (ls_open_dir(av[ac], data) != 0)
				ret = 1;
		}
	}
	return (ret);
}

static int	ls_arg_dir_loop(int ac, char **av, int i, t_ls *data)
{
	struct stat		buf;
	int				ret;

	ret = 0;
	while (i++ < ac - 1)
	{
		if (lstat(av[i], &buf) != -1 && S_ISDIR(buf.st_mode) != 0)
		{
			if (data->arg_files > 0 || data->arg_missing > 0
					|| data->arg_dirs > 0)
				ft_printf("\n%s:\n", av[i]);
			else if (i != ac - 1)
				ft_printf("%s:\n", av[i]);
			data->arg_dirs++;
			if (ls_open_dir(av[i], data) != 0)
				ret = 1;
		}
		else if (S_ISDIR(buf.st_mode) != 0)
			ft_printf("./ft_ls: %s: %s\n", av[i], strerror(errno));
	}
	return (ret);
}

int			ls_arg_dir(int ac, char **av, int i, t_ls *data)
{
	int				ret;

	ret = 0;
	if (data->r_flag == 0)
		ret = ls_arg_dir_loop(ac, av, i, data);
	else
		ret = ls_arg_dir_r_loop(ac, av, i, data);
	return (ret);
}
