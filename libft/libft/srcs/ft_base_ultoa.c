/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_ultoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:13:20 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/12/16 13:40:55 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_base_ultoa(unsigned long long nb,
						int base, char *chararr)
{
	char			*res;
	int				chars;
	unsigned int	ubase;

	chars = ft_ulonglong_numbercount(nb, base);
	if (!(res = (char*)malloc(sizeof(char) * (chars + 1))))
		return (NULL);
	res[chars] = '\0';
	chars--;
	ubase = (unsigned int)base;
	while (nb > (ubase - 1))
	{
		res[chars] = chararr[nb % ubase];
		nb = nb / (long long)ubase;
		chars--;
	}
	res[chars] = chararr[nb % ubase];
	return (res);
}
