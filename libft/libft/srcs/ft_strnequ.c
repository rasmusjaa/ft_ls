/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:20:48 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/10/21 09:31:27 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	i;
	int	nb;

	i = 0;
	nb = n;
	if (s1 && s2)
	{
		while (s1[i] == s2[i] && s1[i] && s2[i] && i < nb)
			i++;
		if (s1[i] == s2[i] || i == nb)
			return (1);
	}
	return (0);
}
