/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:26:46 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/12/16 12:15:33 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int				text_to_node(t_node *current, char *str, int len)
{
	t_node		*temp;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	temp->str = (ft_strndup(str - len, len));
	add_color(temp);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}

int				arg_c_to_node(t_node *current, va_list args)
{
	t_node		*temp;
	char		c;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	temp->str = ft_strdup(" ");
	c = va_arg(args, int);
	if (c == '\0')
	{
		current->cnull = 1;
		c = 'x';
	}
	temp->str[0] = c;
	current->arg = 'c';
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}

int				arg_s_to_node(t_node *current, va_list args)
{
	t_node		*temp;
	char		*s;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	s = va_arg(args, char *);
	if (!s)
		temp->str = ft_strdup(NULL_STRING);
	else
		temp->str = ft_strdup(s);
	current->arg = 's';
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}

int				arg_p_to_node(t_node *current, va_list args)
{
	t_node		*temp;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	temp->str = ft_base_ltoa(va_arg(args, long long), 16, BASE16LC);
	current->arg = 'p';
	temp->str = address_pre(temp->str);
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}

int				arg_d_to_node(t_node *current, va_list args)
{
	t_node		*temp;
	long long	n;

	if (!(temp = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	n = va_arg(args, long long int);
	if (current->ll_flag == 1)
		temp->str = ft_base_ltoa((long long int)n, 10, BASE16LC);
	else if (current->l_flag == 1)
		temp->str = ft_base_ltoa((long int)n, 10, BASE16LC);
	else if (current->h_flag == 1)
		temp->str = ft_base_ltoa((short int)n, 10, BASE16LC);
	else if (current->hh_flag == 1)
		temp->str = ft_base_ltoa((char)n, 10, BASE16LC);
	else
		temp->str = ft_itoa((int)n);
	plus_minus(temp->str, n, current);
	current->arg = 'd';
	flags_from_temp(temp, current);
	current->next = temp;
	current = temp;
	temp->next = NULL;
	return (0);
}
