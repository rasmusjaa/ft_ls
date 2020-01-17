/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaakonm <rjaakonm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:07:49 by rjaakonm          #+#    #+#             */
/*   Updated: 2019/10/20 17:11:52 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_words(char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (!s || s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c && i > 0 && s[i - 1] != c)
			words++;
		i++;
	}
	words++;
	if (i > 0 && s[i - 1] == c)
		words--;
	return (words);
}
