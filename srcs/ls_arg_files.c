/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_arg_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:29:40 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/29 18:27:50 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_get_widths(t_ls *data, struct stat buf, char *str)
{
	struct passwd	*pwd;
	struct group	*grp;
	int				width;

	if (!(pwd = getpwuid(buf.st_uid)))
		ls_error_exit("Getpwuid error\n");
	if (!(grp = getgrgid(buf.st_gid)))
		ls_error_exit("Getgrgid error\n");
	width = ft_ulonglong_numbercount(buf.st_size, 10);
	if (width > data->byte_width)
		data->byte_width = width;
	width = ft_ulonglong_numbercount(buf.st_nlink, 10);
	if (width > data->link_width)
		data->link_width = width;
	data->col_width = ls_if_longer(data->col_width, str);
	data->user_width = ls_if_longer(data->user_width, pwd->pw_name);
	data->group_width = ls_if_longer(data->group_width, grp->gr_name);
}

void		ls_arg_file(int ac, char **av, int i, t_ls *data)
{
	struct stat		buf;
	t_lstext		*node;

	if (!(data->start = (t_lstext *)malloc(sizeof(t_lstext))))
		ls_error_exit("Malloc error\n");
	data->start->str = NULL;
	data->start->next = NULL;
	node = data->start;
	ft_strcpy(data->cur_dir, "./");
	ls_init_layout(data);
	while (i++ < ac - 1)
		if (lstat(av[i], &buf) != -1 && S_ISDIR(buf.st_mode) == 0)
		{
			data->arg_files++;
			data->col_count++;
			node->str = ft_strdup(av[i]);
			ls_get_widths(data, buf, av[i]);
			node = ls_node_new(node);
		}
	data->col_count = data->term_w / (data->col_width + 1);
	data->col_width = -1 * data->col_width;
	data->arg_files > 0 ? ls_print_nodes(data) : free(data->start);
}
