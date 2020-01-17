/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:52:02 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/12/17 12:51:49 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			ft_fd_putstr_ret(int fd, t_node *current)
{
	int		i;
	char	*s;

	i = 0;
	s = current->str;
	if (current->arg == 'c')
	{
		while (s[i])
		{
			if (current->cnull == 1 && s[i] == 'x')
				s[i] = '\0';
			i++;
		}
		write(fd, s, i);
	}
	else
	{
		while (s[i])
		{
			i++;
		}
		write(fd, s, i);
	}
	return (i);
}

int			ft_putstr_ret(t_node *current)
{
	int		i;
	char	*s;

	i = 0;
	s = current->str;
	if (current->arg == 'c')
	{
		while (s[i])
		{
			if (current->cnull == 1 && s[i] == 'x')
				s[i] = '\0';
			i++;
		}
		write(1, s, i);
	}
	else
	{
		while (s[i])
		{
			i++;
		}
		write(1, s, i);
	}
	return (i);
}

char		*ft_strndup(const char *s, int len)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i] && i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
