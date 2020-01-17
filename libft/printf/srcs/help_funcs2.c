/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:38:29 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/12/02 17:48:42 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*swap_sign2(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] == '0')
		i++;
	if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != 0)
	{
		str[i] = '0';
		str[0] = ' ';
	}
	if ((str[i] == 'x' || str[i] == 'X') && i != 1)
	{
		str[1] = str[i];
		str[i] = '0';
	}
	i = 0;
	while (str[i] == ' ')
		i++;
	if (i > 1 && str[i - 1] == ' ' && str[i] != ' ' && str[i] != 0)
	{
		str[i - 1] = '0';
		str[0] = ' ';
	}
	return (str);
}

void		swap_sign(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '0')
	{
		while (str[i] && str[i] != '-' && str[i] != '+')
			i++;
		if (str[i] == '-' || str[i] == '+' || (str[i] == ' ' && i == 0))
		{
			str[0] = str[i];
			str[i] = '0';
		}
	}
	if (str[0] == '0')
		str = swap_sign2(str);
}
