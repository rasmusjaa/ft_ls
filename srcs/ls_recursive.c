/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:11:10 by rjaakonm          #+#    #+#             */
/*   Updated: 2020/01/29 18:02:31 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			start_again(char *str, t_ls *old_data)
{
	t_ls	*data;

	if (!(data = (t_ls *)malloc(sizeof(t_ls))))
		ls_error_exit("Malloc error\n");
	ft_strcpy(data->cur_dir, str);
	if (ls_ends_in_slash(data->cur_dir) == 1)
		ft_strcat(data->cur_dir, "/");
	data->cur_col = 0;
	data->term_w = old_data->term_w;
	data->l_flag = old_data->l_flag;
	data->cr_flag = old_data->cr_flag;
	data->a_flag = old_data->a_flag;
	data->r_flag = old_data->r_flag;
	data->t_flag = old_data->t_flag;
	data->ct_flag = old_data->ct_flag;
	ls_open_dir(str, data);
	free(data);
	return (0);
}
