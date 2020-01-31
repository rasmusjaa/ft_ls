/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:25:10 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/31 14:04:35 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_list_swap(t_lstext *node)
{
	char			*tmp;

	tmp = node->str;
	node->str = node->next->str;
	node->next->str = tmp;
}

static void	ls_sort_modified(t_ls *data)
{
	t_lstext		*node;
	char			str1[2048];
	char			str2[2048];
	struct stat		buf1;
	struct stat		buf2;

	node = data->start;
	while (node->next->next)
	{
		ft_strcat(ft_strcpy(str1, data->cur_dir), node->str);
		ft_strcat(ft_strcpy(str2, data->cur_dir), node->next->str);
		lstat(str1, &buf1);
		lstat(str2, &buf2);
		if (buf1.st_mtime < buf2.st_mtime)
		{
			ls_list_swap(node);
			node = data->start;
		}
		else
			node = node->next;
	}
}

static void	ls_sort_az(t_ls *data)
{
	t_lstext		*node;

	node = data->start;
	while (node->next->next)
	{
		if (ft_strcmp(node->str, node->next->str) > 0)
		{
			ls_list_swap(node);
			node = data->start;
		}
		else
			node = node->next;
	}
}

int			ls_sort_dir(t_ls *data)
{
	if (data->t_flag == 1)
		ls_sort_modified(data);
	else
		ls_sort_az(data);
	ls_print_nodes(data);
	return (0);
}
