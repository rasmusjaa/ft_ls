/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:24:35 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/10/20 17:31:09 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*res;
	t_list	*node;

	if (!lst || !f)
		return (NULL);
	res = f(lst);
	if (!(node = ft_lstnew(res->content, res->content_size)))
		return (NULL);
	new = node;
	lst = lst->next;
	while (lst)
	{
		res = f(lst);
		if (!(node->next = ft_lstnew(res->content, res->content_size)))
			return (NULL);
		node = node->next;
		lst = lst->next;
	}
	return (new);
}
