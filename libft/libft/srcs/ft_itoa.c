/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:21:47 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/13 16:07:48 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	nb;
	char	*res;
	int		chars;

	nb = n;
	chars = ft_int_numbercount(n);
	if (!(res = (char*)malloc(sizeof(char) * (chars + 1))))
		return (NULL);
	if (nb < 0)
	{
		nb = nb * -1;
		res[0] = '-';
	}
	res[chars] = '\0';
	chars--;
	while (nb > 9)
	{
		res[chars] = nb % 10 + '0';
		nb = nb / 10;
		chars--;
	}
	res[chars] = nb % 10 + '0';
	return (res);
}
