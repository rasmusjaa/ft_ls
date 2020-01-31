/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_help_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:44:48 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/29 17:32:13 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_error_exit(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

void		ls_usage(t_ls *data)
{
	free(data);
	ft_printf("usage: ./ft_ls [-lRart] [directory ...]\n");
	exit(1);
}

t_lstext	*ls_node_new(t_lstext *node)
{
	if (!(node->next = (t_lstext *)malloc(sizeof(t_lstext))))
		ls_error_exit("Malloc error\n");
	node = node->next;
	node->next = NULL;
	node->str = NULL;
	return (node);
}

int			ls_free_all(t_lstext *node)
{
	t_lstext		*tmp;

	while (node->next)
	{
		tmp = node;
		node = node->next;
		free(tmp->str);
		free(tmp);
	}
	free(node->str);
	free(node);
	return (0);
}

int			ls_is_not_dot(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == '.' && str[i - 2] == '.' && str[i - 3] == '/')
		return (1);
	if (str[i - 1] == '.' && str[i - 2] == '/')
		return (1);
	if (str[0] == '.' && str[1] == '\0')
		return (1);
	if (str[0] == '.' && str[1] == '.' && str[1] == '\0')
		return (1);
	return (0);
}
