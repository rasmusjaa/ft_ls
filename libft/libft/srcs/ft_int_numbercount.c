/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_numbercount.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:10:04 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/10/19 17:54:05 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_int_numbercount(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 1;
	if (nb < 0)
	{
		count++;
		nb = nb * -1;
	}
	while (nb > 9)
	{
		count++;
		nb = nb / 10;
	}
	return (count);
}
