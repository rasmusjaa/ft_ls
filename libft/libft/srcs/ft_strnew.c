/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:19:14 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/10/19 16:37:15 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*string;
	int		size2;

	size2 = size;
	if (!(string = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (size2 >= 0)
	{
		string[size2] = '\0';
		size2--;
	}
	return (string);
}
