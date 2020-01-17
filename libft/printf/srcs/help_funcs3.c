/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:11:46 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/12/03 12:59:37 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	add_empty_f(t_node *temp)
{
	char	*tmp;
	int		i;

	if (temp->str[0] != '-' && temp->str[0] != '+' && temp->str[0] != ' ')
	{
		if (temp->str[0] == '0')
			temp->str[0] = ' ';
		else
		{
			tmp = temp->str;
			temp->str = ft_strjoin(" ", tmp);
			free(tmp);
			i = 0;
			while (temp->str[i])
				i++;
			if (temp->str[i - 1] == ' ')
				temp->str[i - 1] = 0;
		}
	}
}

void		add_empty(t_node *temp, t_node *current)
{
	char	*tmp;

	if (current->arg == 'd')
	{
		if (temp->str[0] != '-' && temp->str[0] != '+')
		{
			tmp = temp->str;
			temp->str = ft_strjoin(" ", tmp);
			free(tmp);
		}
	}
	if (current->arg == 'f')
		add_empty_f(temp);
}

char		*address_pre(char *str)
{
	char	pre[3];
	char	*tmp;

	pre[0] = '0';
	pre[1] = 'x';
	pre[2] = 0;
	tmp = ft_strjoin(pre, str);
	free(str);
	return (tmp);
}

int			set_prefixes(char *str, t_node *current)
{
	if (str[0] == 'l')
	{
		if (str[1] == 'l')
		{
			current->ll_flag = 1;
			return (2);
		}
		current->l_flag = 1;
	}
	if (str[0] == 'h')
	{
		if (str[1] == 'h')
		{
			current->hh_flag = 1;
			return (2);
		}
		current->h_flag = 1;
	}
	if (str[0] == 'L')
		current->ucl_flag = 1;
	return (1);
}
