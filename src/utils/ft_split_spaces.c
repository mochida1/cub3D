/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 14:47:15 by viferrei          #+#    #+#             */
/*   Updated: 2023/01/21 17:16:15 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int	ft_isspacetab(char c)
{
	if (c == '\t' || c == ' ' || c == '\n')
		return (1);
	else
		return (0);
}

size_t	ft_split_spaces_count(char const *s)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if (!ft_isspacetab(*s))
		{
			count++;
			while (*s != '\0' && !ft_isspacetab(*s))
				s++;
		}
		else
			s++;
	}
	return (count);
}

/*
//	Splits the string s into a string array using spaces and tabs as delimiters.
*/
char	**ft_split_spaces(char const *s)
{
	size_t		len;
	size_t		index;
	const char	*start;
	char		**split;

	split = (char **) malloc(((ft_split_spaces_count(s)) + 1) * sizeof(*split));
	if (!split)
		return (0);
	index = 0;
	while (*s != '\0')
	{
		while (*s && ft_isspacetab(*s))
			s++;
		start = s;
		len = 0;
		while (*s && !ft_isspacetab(*s))
		{
			s++;
			len++;
		}
		if (!ft_isspacetab(*(s - 1)))
			split[index++] = ft_substr(start, 0, len);
	}
	split[index] = 0;
	return (split);
}
