/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:45:27 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/30 16:18:28 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_recurse_normal(t_ls *data, t_lstext *node)
{
	DIR				*dir;
	char			str[2048];
	struct stat		buf;

	if (node->next)
	{
		if (data->cr_flag == 1)
		{
			ft_strcat(ft_strcpy(str, data->cur_dir), node->str);
			lstat(str, &buf);
			if (S_ISDIR(buf.st_mode))
			{
				dir = opendir(str);
				if (dir != NULL && (ls_is_not_dot(str) == 0))
				{
					closedir(dir);
					ft_printf("\n%s:\n", str);
					start_again(str, data);
				}
				if (dir != NULL && (ls_is_not_dot(str) == 1))
					closedir(dir);
			}
		}
		ls_recurse_normal(data, node->next);
	}
}

void		ls_output_l(t_ls *data, t_lstext *node)
{
	struct stat		buf;
	char			path[2048];

	ft_strcat(ft_strcpy(path, data->cur_dir), node->str);
	if (lstat(path, &buf) == -1)
	{
		ft_printf("./ft_ls: %s: %s\n", path, strerror(errno));
		data->printed++;
		return ;
	}
	ls_parse_l_flag(data, buf, node->str, path);
	data->printed++;
}

void		ls_output_no_l(t_ls *data, t_lstext *node)
{
	data->cur_col += 1;
	if (data->cur_col >= data->col_count)
	{
		ft_putchar('\n');
		data->cur_col = 0;
	}
	ft_printf("%*s", data->col_width - 1, node->str);
	data->printed++;
}

static int	ls_print_normal(t_ls *data, t_lstext *node)
{
	if (node->next)
	{
		if (data->l_flag == 1)
			ls_output_l(data, node);
		else
			ls_output_no_l(data, node);
		ls_print_normal(data, node->next);
	}
	return (0);
}

int			ls_print_nodes(t_ls *data)
{
	t_lstext		*node;

	node = data->start;
	data->printed = 0;
	if (data->r_flag == 1)
	{
		ls_print_rev(data, node);
		if (data->printed != 0 && data->l_flag == 0)
			ft_putchar('\n');
		ls_recurse_rev(data, node);
	}
	else
	{
		ls_print_normal(data, node);
		if (data->printed != 0 && data->l_flag == 0)
			ft_putchar('\n');
		ls_recurse_normal(data, node);
	}
	ls_free_all(data->start);
	data->cur_col = 0;
	return (0);
}
