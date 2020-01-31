/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:50:07 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/31 14:44:15 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_get_widths(t_ls *data, struct stat buf, struct dirent *sd)
{
	struct passwd	*pwd;
	struct group	*grp;
	int				width;

	if (!(pwd = getpwuid(buf.st_uid)))
		ls_error_exit("getpwuid error\n");
	if (!(grp = getgrgid(buf.st_gid)))
		ls_error_exit("getgrgid error\n");
	width = ft_ulonglong_numbercount(buf.st_size, 10);
	if (width > data->byte_width)
		data->byte_width = width;
	width = ft_ulonglong_numbercount(buf.st_nlink, 10);
	if (width > data->link_width)
		data->link_width = width;
	data->col_width = ls_if_longer(data->col_width, sd->d_name);
	data->user_width = ls_if_longer(data->user_width, pwd->pw_name);
	data->group_width = ls_if_longer(data->group_width, grp->gr_name);
}

static int		ls_layout(t_ls *data, char *str)
{
	DIR				*dir;
	struct dirent	*sd;
	struct stat		buf;
	char			path[2048];

	dir = opendir(str);
	if (dir == NULL)
		return (1);
	ls_init_layout(data);
	while ((sd = readdir(dir)) != NULL)
	{
		ft_strcat(ft_strcpy(path, data->cur_dir), sd->d_name);
		if (ls_is_not_dot(path) == 0 || data->a_flag == 1)
		{
			if (lstat(path, &buf) == -1)
				return (ls_closedir_error(dir));
			else
				ls_get_widths(data, buf, sd);
		}
		data->dir_contains++;
	}
	ls_calc_columns(data);
	closedir(dir);
	return (0);
}

static t_lstext	*ls_make_list(t_ls *data, DIR *dir)
{
	t_lstext		*node;
	struct dirent	*sd;

	node = data->start;
	while ((sd = readdir(dir)) != NULL)
	{
		if (sd->d_name[0] != '.' || data->a_flag == 1)
		{
			node->str = ft_strdup(sd->d_name);
			node = ls_node_new(node);
		}
	}
	return (node);
}

int				ls_open_dir(char *str, t_ls *data)
{
	DIR				*dir;
	struct stat		buf;

	lstat(str, &buf);
	ft_strcpy(data->cur_dir, str);
	if (ls_ends_in_slash(data->cur_dir) == 1)
		ft_strcat(data->cur_dir, "/");
	if (ls_layout(data, str) == 1)
	{
		ft_printf("./ft_ls: %s: %s\n", str, strerror(errno));
		return (1);
	}
	if (data->l_flag == 1 && (data->dir_contains > 2 || data->a_flag == 1))
		ft_printf("total %d\n", ls_total_dir(str));
	if (!(data->start = (t_lstext *)malloc(sizeof(t_lstext))))
		ls_error_exit("Malloc error\n");
	data->start->next = NULL;
	data->start->str = NULL;
	dir = opendir(str);
	if (ls_make_list(data, dir) != data->start)
		ls_sort_dir(data);
	else
		ls_free_all(data->start);
	closedir(dir);
	return (0);
}

int				ls_read(int ac, char **av, int i, t_ls *data)
{
	int				ret;

	ret = 0;
	if (!av[i])
		ls_open_dir(".", data);
	else
	{
		ls_sort_args(ac, av, i, data);
		i = i - 1;
		if (ls_arg_exists(ac, av, i, data) == 1)
			ret = 1;
		ls_arg_file(ac, av, i, data);
		if (ls_arg_dir(ac, av, i, data) == 1)
			ret = 1;
	}
	return (ret);
}
