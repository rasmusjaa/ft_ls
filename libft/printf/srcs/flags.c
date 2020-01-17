/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:53:15 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/12/03 12:54:31 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	add_hash(t_node *temp, t_node *current)
{
	char	*tmp;

	if (current->arg == 'o' && temp->str[0] != '0')
	{
		tmp = temp->str;
		temp->str = ft_strjoin("0", tmp);
		free(tmp);
	}
	if ((current->arg == 'x' || current->arg == 'X') && current->nb != 0)
	{
		tmp = temp->str;
		temp->str = ft_strjoin(current->arg == 'x' ? "0x" : "0X", tmp);
		free(tmp);
	}
	if (current->arg == 'f' && current->precision == 0)
	{
		tmp = temp->str;
		temp->str = ft_strjoin(tmp, ".");
		free(tmp);
	}
}

void		flags_from_temp(t_node *temp, t_node *current)
{
	char	*tmp;

	move_flags(temp, current);
	if (current->plus_flag == 1 && (current->arg == 'd' || current->arg == 'f'))
	{
		if (temp->str[0] == '-')
			current->plus_flag = 0;
		else
		{
			tmp = temp->str;
			temp->str = ft_strjoin("+", tmp);
			free(tmp);
		}
	}
	if (current->precision_set == 1)
		add_precision(temp, current->precision);
	if (current->empty == 1 && current->arg != 'f')
		add_empty(temp, current);
	if (current->hash == 1)
		add_hash(temp, current);
	add_width(temp);
	swap_sign(temp->str);
	if (current->empty == 1 && current->arg == 'f')
		add_empty(temp, current);
}

static int	check_from_arg(char **str, t_node *current, va_list args)
{
	int		nb;

	nb = va_arg(args, int);
	*str = (*str) - 1;
	if (**str == '.')
	{
		current->precision_set = 1;
		current->precision = nb;
	}
	else
		current->width = nb;
	*str = (*str) + 2;
	return (1);
}

static int	check_flags2(char **str, t_node *current)
{
	if (**str == '-' || **str == '+')
	{
		*str = (*str) + plus_minus2(*str, current);
		return (1);
	}
	if (**str == ' ')
	{
		*str = (*str) + 1;
		current->empty = 1;
		return (1);
	}
	if (ft_isdigit(**str))
	{
		*str = (*str) + check_width(*str, current);
		return (1);
	}
	if (**str == 'h' || **str == 'l' || **str == 'L')
	{
		*str = (*str) + set_prefixes(*str, current);
		return (1);
	}
	return (-1);
}

int			check_flags(char **str, t_node *current, va_list args)
{
	if (**str == '.')
	{
		*str = (*str) + check_precision(*str, current);
		return (1);
	}
	if (**str == '0' && !(ft_isdigit(*(*str - 1))))
	{
		current->space = 1;
		*str = (*str) + 1;
		return (1);
	}
	if (**str == '#')
	{
		current->hash = 1;
		*str = (*str) + 1;
		return (1);
	}
	if (**str == '*')
		return (check_from_arg(str, current, args));
	return (check_flags2(str, current));
}
