/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_funcs3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:41:12 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/12/16 13:47:01 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int							arg_percent_to_node(t_node *current)
{
	t_node					*temp;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	temp->str = ft_strdup(" ");
	temp->str[0] = '%';
	current->arg = '%';
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}

int							arg_b_to_node(t_node *current, va_list args)
{
	t_node					*temp;
	long long unsigned int	n;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	n = va_arg(args, unsigned long long);
	current->nb = n;
	if (current->ll_flag == 1)
		temp->str = ft_base_ultoa(n, 2, BASE16LC);
	else if (current->l_flag == 1)
		temp->str = ft_base_ultoa((unsigned long)n, 2, BASE16LC);
	else
		temp->str = ft_base_ultoa((unsigned int)n, 2, BASE16LC);
	current->arg = 'd';
	plus_minus(temp->str, n, current);
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}
