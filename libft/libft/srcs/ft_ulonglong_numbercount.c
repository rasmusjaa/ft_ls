/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulonglong_numbercount.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:20:32 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/12/16 13:40:08 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_ulonglong_numbercount(unsigned long long nb, int base)
{
	int				count;
	unsigned int	bases;

	count = 1;
	bases = (unsigned int)base;
	while (nb > (bases - 1))
	{
		count++;
		nb = nb / bases;
	}
	return (count);
}
