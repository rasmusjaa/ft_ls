/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:52:19 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/12/03 12:37:06 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_types g_types[N_TYPES] =
{
	{'c', arg_c_to_node},
	{'s', arg_s_to_node},
	{'p', arg_p_to_node},
	{'d', arg_d_to_node},
	{'i', arg_d_to_node},
	{'o', arg_o_to_node},
	{'u', arg_u_to_node},
	{'x', arg_x_to_node},
	{'X', arg_ucx_to_node},
	{'f', arg_f_to_node},
	{'b', arg_b_to_node},
};

void		default_flags(t_node *current)
{
	current->plus_flag = 0;
	current->minus_flag = 0;
	current->width = 0;
	current->precision = 6;
	current->precision_set = 0;
	current->space = 0;
	current->empty = 0;
	current->hash = 0;
	current->l_flag = 0;
	current->ll_flag = 0;
	current->ucl_flag = 0;
	current->h_flag = 0;
	current->hh_flag = 0;
	current->nb = 0;
	current->float_left = 0.0;
	current->float_right = 0.0;
	current->cnull = 0;
	current->arg = '0';
}

void		move_flags(t_node *temp, t_node *current)
{
	temp->width = current->width;
	temp->precision = current->precision;
	temp->precision_set = current->precision_set;
	temp->plus_flag = current->plus_flag;
	temp->minus_flag = current->minus_flag;
	temp->arg = current->arg;
	temp->space = current->space;
	temp->empty = current->empty;
	temp->hash = current->hash;
	temp->nb = current->nb;
	temp->float_left = current->float_left;
	temp->float_right = current->float_right;
	temp->cnull = current->cnull;
}
