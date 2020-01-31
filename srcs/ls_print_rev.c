/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_rev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:45:27 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/30 16:18:41 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_recurse_rev(t_ls *data, t_lstext *node)
{
	DIR				*dir;
	char			str[2048];
	struct stat		buf;

	if (node->next)
	{
		ls_recurse_rev(data, node->next);
		if (data->cr_flag == 1)
		{
			ft_strcat(ft_strcpy(str, data->cur_dir), node->str);
			lstat(str, &buf);
			if (S_ISDIR(buf.st_mode))
			{
				dir = opendir(str);
				if (dir != NULL && ls_is_not_dot(str) == 0)
				{
					closedir(dir);
					ft_printf("\n%s:\n", str);
					start_again(str, data);
				}
				if (dir != NULL && (ls_is_not_dot(str) == 1))
					closedir(dir);
			}
		}
	}
}

int		ls_print_rev(t_ls *data, t_lstext *node)
{
	if (node->next)
	{
		ls_print_rev(data, node->next);
		if (data->l_flag == 1)
			ls_output_l(data, node);
		else
			ls_output_no_l(data, node);
	}
	return (0);
}
