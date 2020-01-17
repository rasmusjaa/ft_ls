/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_floats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:39:31 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/12/03 13:04:23 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char				*float_begin(long double nb, t_node *current)
{
	int					x;
	int					y;
	double				nb2;
	char				*s1;

	x = 0;
	y = 0;
	nb2 = 0;
	while (nb >= 1)
	{
		nb = nb / 10;
		x++;
	}
	s1 = x > 0 ? ft_strnew(x) : ft_strdup("0");
	while (x > 0)
	{
		nb = nb * 10;
		s1[y] = (int)nb + '0';
		nb2 = nb2 * 10 + (int)nb;
		nb = nb - (int)nb;
		x--;
		y++;
	}
	current->float_left = nb2;
	return (s1);
}

static long double		double_divide(long double nb, int n, int divider)
{
	if (n <= 0)
		return (0);
	while (n > 0)
	{
		nb = nb / divider;
		n--;
	}
	return (nb);
}

static char				*float_end(long double nb, t_node *current)
{
	int					x;
	double				nb2;
	char				*s2;
	int					not;

	x = 0;
	not = 0;
	nb2 = 0;
	s2 = ft_strnew(current->precision);
	while (nb >= 1)
		nb = nb - double_divide(0.5, current->precision, 10);
	while (x < current->precision)
	{
		nb = nb * 10;
		if ((int)nb >= 10)
			return (NULL);
		s2[x] = (int)(nb) + '0';
		nb2 = nb2 * 10 + (int)nb;
		nb = nb - (double)(int)nb;
		x++;
	}
	if (nb * 10 >= 5 && current->precision >= 19 && s2[x - 1] < '9')
		s2[x - 1]++;
	current->float_right = nb2;
	return (s2);
}

static char				*join_sides(char *s1, char *s2, char *dbl)
{
	s1 = dbl;
	dbl = ft_strjoin(dbl, ".");
	free(s1);
	s1 = dbl;
	dbl = ft_strjoin(dbl, s2);
	free(s1);
	return (dbl);
}

char					*ft_ftoa(long double nb, t_node *current)
{
	char				*s1;
	char				*s2;
	char				*dbl;
	char				sign[2];

	sign[0] = nb < 0 ? '-' : 0;
	sign[1] = 0;
	if (nb < 0)
		nb = nb * -1;
	nb = nb + double_divide(0.5, current->precision, 10);
	s1 = float_begin(nb, current);
	if (nb - current->float_left >= 0.5 && current->precision <= 0)
	{
		free(s1);
		s1 = float_begin(nb + 1, current);
	}
	s2 = float_end(nb - current->float_left, current);
	dbl = ft_strjoin(sign, s1);
	free(s1);
	if (current->precision > 0)
		dbl = join_sides(s1, s2, dbl);
	free(s2);
	return (dbl);
}
