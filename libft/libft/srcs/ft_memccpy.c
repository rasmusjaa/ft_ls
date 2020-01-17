/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:14:54 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/10/20 17:55:22 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	c2;

	if (dest == src || n <= 0)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	c2 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s[i] == c2)
		{
			(d[i] = s[i]);
			return (&d[i + 1]);
		}
		else
		{
			(d[i] = s[i]);
			i++;
		}
	}
	return (NULL);
}
