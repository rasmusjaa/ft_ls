/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:20:04 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/10/19 17:45:56 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_rev(char *s)
{
	int		i;
	int		end;
	char	tmp;

	i = 0;
	if (!s || s[i] == '\0')
		return (s);
	end = ft_strlen(s) - 1;
	while (i < (end / 2 + 1))
	{
		tmp = s[i];
		s[i] = s[end - i];
		s[end - i] = tmp;
		i++;
	}
	return (s);
}
