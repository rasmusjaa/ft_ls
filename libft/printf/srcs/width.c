/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:16:43 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/29 20:03:15 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	move_and_free(t_node *cur, char *tmp, char *tmp2)
{
	free(cur->str);
	free(tmp);
	cur->str = tmp2;
}

void		add_width(t_node *cur)
{
	int		len;
	int		diff;
	char	*tmp;
	char	*tmp2;
	char	c;

	c = ' ';
	if (cur->space == 1 && (is_nb(cur->arg) || cur->arg == '%') &&
			cur->width > 0 && (cur->precision_set == 0 || cur->arg == 'f'))
		c = '0';
	len = ft_strlen(cur->str);
	if (cur->width > 0 && cur->width > len)
	{
		diff = cur->width - len;
		tmp = ft_strnew_c(diff, c);
		tmp2 = ft_strjoin(tmp, cur->str);
		move_and_free(cur, tmp, tmp2);
	}
	if (cur->width < 0 && (-1 * cur->width) > len)
	{
		diff = -1 * cur->width - len;
		tmp = ft_strnew_c(diff, c);
		tmp2 = ft_strjoin(cur->str, tmp);
		move_and_free(cur, tmp, tmp2);
	}
}

static void	add_precision_nb(t_node *current, int precision, char *temp)
{
	int		diff;
	char	*tmp;
	char	*tmp2;

	if (current->str[0] == '-' || current->str[0] == '+')
		precision++;
	if (precision == 0 && current->str[0] == '0' && current->plus_flag == 0
		&& current->arg != 'f')
	{
		current->str = ft_strdup("");
		free(temp);
	}
	if (precision == 1 && current->str[1] == '0' && current->plus_flag == 1)
	{
		current->str = ft_strdup("+");
		free(temp);
	}
	if (precision > (int)ft_strlen(current->str))
	{
		diff = precision - ft_strlen(current->str);
		tmp = ft_strnew_c(diff, '0');
		tmp2 = ft_strjoin(tmp, current->str);
		swap_sign(tmp2);
		move_and_free(current, tmp, tmp2);
	}
}

void		add_precision(t_node *current, int precision)
{
	char	*temp;

	temp = current->str;
	if (current->arg == 's' && (int)ft_strlen(current->str) > precision)
	{
		if (precision == 0 && current->width != 0)
			current->str = ft_strdup(" ");
		else
			current->str = ft_strsub(current->str, 0, precision);
		free(temp);
	}
	if (is_nb(current->arg))
		add_precision_nb(current, precision, temp);
}
