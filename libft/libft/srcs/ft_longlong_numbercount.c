/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlong_numbercount.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:20:32 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/13 16:44:13 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_longlong_numbercount(long long n, int base)
{
	long long	nb;
	int			count;

	nb = n;
	count = 1;
	if (nb < 0)
	{
		count++;
		nb = nb * -1;
	}
	while (nb > (base - 1))
	{
		count++;
		nb = nb / base;
	}
	return (count);
}
