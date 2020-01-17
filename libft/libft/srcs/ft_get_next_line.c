/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:00:21 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/08 14:26:03 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			trimline(char **str, int fd, int st, int end)
{
	char		*trimmed;
	int			i;

	if (!(trimmed = (char *)malloc(sizeof(char) * (end - st + 1))))
		return ;
	i = 0;
	while (st + i < end)
	{
		trimmed[i] = str[fd][st + i];
		i++;
	}
	trimmed[i] = '\0';
	free(str[fd]);
	str[fd] = trimmed;
}

int				process_line(char **str, int fd, char **line)
{
	int			len1;
	int			len2;

	len1 = 0;
	while (str[fd][len1] != '\n' && str[fd][len1] != '\0')
		len1++;
	len2 = len1;
	while (str[fd][len2])
		len2++;
	if (str[fd][len1] == '\n')
	{
		*line = ft_strsub(str[fd], 0, len1);
		trimline(str, fd, len1 + 1, len2);
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][len1] == '\0')
	{
		*line = strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int				ft_get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*temp;
	static char	*strings[MAX_FD];

	if (!line || fd < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (strings[fd] == '\0')
			strings[fd] = ft_strnew(0);
		temp = ft_strjoin(strings[fd], buf);
		free(strings[fd]);
		strings[fd] = temp;
		if (ft_strchr(buf, '\n') > 0)
			break ;
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (strings[fd] == NULL || strings[fd][0] == '\0'))
		return (0);
	return (process_line(strings, fd, line));
}
