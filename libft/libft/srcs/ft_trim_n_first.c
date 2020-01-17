/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_n_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:44:06 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/12/17 12:46:42 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_trim_n_first(int n, char *str)
{
	char	*tmp;

	tmp = ft_strdup(&str[n]);
	free(str);
	str = tmp;
	return (str);
}
