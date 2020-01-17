/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:21:24 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/10/21 09:41:55 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trimmed;
	int		i;
	int		st;
	int		end;

	st = 0;
	if (!s)
		return (NULL);
	while (s[st] && (s[st] == ' ' || s[st] == '\n' || s[st] == '\t'))
		st++;
	end = ft_strlen(s);
	while (end > st && (s[end] == ' ' ||
			s[end] == '\n' || s[end] == '\t' || s[end] == '\0'))
		end--;
	end++;
	if (!(trimmed = (char *)malloc(sizeof(char) * (end - st + 1))))
		return (NULL);
	i = 0;
	while (st + i < end)
	{
		trimmed[i] = s[st + i];
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
