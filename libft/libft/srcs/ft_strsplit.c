/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:21:35 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/10/20 17:12:38 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	char	**array;
	int		words;

	i = 0;
	j = 0;
	words = ft_count_words((char *)s, c);
	if (!(array = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (j < words)
	{
		while (s[i] == c)
			i++;
		len = ft_len_itoc((char *)s, i, c);
		if (!(array[j] = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		array[j] = ft_strncpy(array[j], &s[i], len);
		array[j][len] = '\0';
		j++;
		i = i + len;
	}
	array[words] = NULL;
	return (array);
}
