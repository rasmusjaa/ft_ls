/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:14:48 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/11/25 11:09:27 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long		ft_pow(long long n, int pow)
{
	int			i;
	long long	total;

	i = 1;
	total = n;
	while (i < pow)
	{
		total = total * n;
		i++;
	}
	return (total);
}
