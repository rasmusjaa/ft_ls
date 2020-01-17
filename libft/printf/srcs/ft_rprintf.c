/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:02:30 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/12/17 13:43:16 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*to_string_list(t_node *start, int len)
{
	t_node	*temp;
	char	*final;

	final = ft_strnew(len);
	temp = start;
	start = start->next;
	free(temp);
	while (start->next != NULL)
	{
		ft_strcat(final, start->str);
		temp = start;
		start = start->next;
		free(temp->str);
		free(temp);
	}
	ft_strcat(final, start->str);
	temp = start;
	start = start->next;
	free(temp->str);
	free(temp);
	return (final);
}

static char	*return_list(t_node *start)
{
	int		total;
	t_node	*temp;
	t_node	*begin;

	total = 0;
	begin = start;
	temp = start;
	start = start->next;
	while (start->next != NULL)
	{
		total = total + ft_strlen(start->str);
		temp = start;
		start = start->next;
	}
	total = total + ft_strlen(start->str);
	return (to_string_list(begin, total));
}

static char	*rparse(char *str, va_list args, t_node *start)
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
				return (NULL);
			current = current->next;
		}
		if (*(str) == '\0')
			break ;
		++str;
		if ((check_arg(&str, args, current)) == -1)
			return (NULL);
		current = current->next;
	}
	return (return_list(start));
}

char		*ft_rprintf(const char *format, ...)
{
	char	*str;
	va_list	args;
	t_node	*start;
	char	*rvalue;

	if (!(start = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	start->next = NULL;
	va_start(args, format);
	str = (char *)format;
	if (!str || str[0] == 0)
	{
		free(start);
		return (NULL);
	}
	rvalue = rparse(str, args, start);
	va_end(args);
	return (rvalue);
}
