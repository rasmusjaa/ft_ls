/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:59:50 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/29 20:27:05 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int ac, char **av)
{
	t_ls		*data;
	int			ret;

	if (!(data = (t_ls *)malloc(sizeof(t_ls))))
		ls_error_exit("Malloc error\n");
	ret = ls_options(ac, av, data);
	free(data);
	return (ret);
}
