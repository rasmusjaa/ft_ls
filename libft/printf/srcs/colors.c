/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:48:07 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/12/02 17:51:28 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_colors g_colors[N_COLORS] =
{
	{"blue", "\033[0;34m"},
	{"cyan", "\033[0;36m"},
	{"green", "\033[0;32m"},
	{"magenta", "\033[0;35m"},
	{"red", "\033[0;31m"},
	{"yellow", "\033[0;33m"},
	{"bblue", "\033[1;34m"},
	{"bcyan", "\033[1;36m"},
	{"bgreen", "\033[1;32m"},
	{"bmagenta", "\033[1;35m"},
	{"bred", "\033[1;31m"},
	{"byellow", "\033[1;33m"},
	{"eoc", "\033[0m"},
};

static char	*replace(char *str, int start, int len, char *code)
{
	char	*tmp;
	char	*tmp2;
	char	*begin;
	char	*end;

	begin = ft_strsub(str, 0, start);
	end = ft_strsub(str, start + len, ft_strlen(&str[start + len]));
	tmp = ft_strjoin(begin, code);
	tmp2 = ft_strjoin(tmp, end);
	free(begin);
	free(end);
	free(tmp);
	return (tmp2);
}

static int	match_color(char *color, char *str)
{
	int		i;

	i = 0;
	while (color[i] == str[i])
		i++;
	if (color[i] == '\0' && str[i] == '}')
		return (i);
	return (0);
}

void		add_color(t_node *temp)
{
	int		i;
	int		len;
	int		k;
	char	*tmp;

	i = 0;
	while (temp->str[i] != 0)
	{
		if (temp->str[i] == '{')
		{
			k = 0;
			while (k < N_COLORS)
			{
				len = 2 + match_color(g_colors[k].color, &temp->str[i + 1]);
				if (len != 2)
				{
					tmp = temp->str;
					temp->str = replace(temp->str, i, len, g_colors[k].code);
					free(tmp);
				}
				k++;
			}
		}
		i++;
	}
}
