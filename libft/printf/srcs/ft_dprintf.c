/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:47:32 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/12/17 13:42:56 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	dprint_list(int fd, t_node *start)
{
	int		total;
	t_node	*temp;

	total = 0;
	temp = start;
	start = start->next;
	free(temp);
	while (start->next != NULL)
	{
		total = total + ft_fd_putstr_ret(fd, start);
		temp = start;
		start = start->next;
		free(temp->str);
		free(temp);
	}
	total = total + ft_fd_putstr_ret(fd, start);
	temp = start;
	start = start->next;
	free(temp->str);
	free(temp);
	return (total);
}

static int	dparse(int fd, char *str, va_list args, t_node *start)
{
	size_t	len;
	t_node	*current;

	current = start;
	while (*str)
	{
		len = 0;
		while (*(str + len) && *(str + len) != '%')
			len++;
		str = str + len;
		if (len > 0)
		{
			if ((text_to_node(current, str, len) == -1))
				return (-1);
			current = current->next;
		}
		if (*(str) == '\0')
			break ;
		++str;
		if ((check_arg(&str, args, current)) == -1)
			return (-1);
		current = current->next;
	}
	return (dprint_list(fd, start));
}

int			ft_dprintf(int fd, const char *format, ...)
{
	char	*str;
	va_list	args;
	t_node	*start;
	int		rvalue;

	if (!(start = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	start->next = NULL;
	va_start(args, format);
	str = (char *)format;
	if (!str || str[0] == 0)
	{
		free(start);
		return (0);
	}
	rvalue = dparse(fd, str, args, start);
	if (rvalue == -1)
		return (0);
	va_end(args);
	return (rvalue);
}
