/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 00:44:38 by coder             #+#    #+#             */
/*   Updated: 2023/01/10 21:03:35 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*safe_free(void *content)
{
	if (content != NULL)
	{
		free (content);
		content = NULL;
		return (NULL);
	}
	return (NULL);
}

void	*free_string_array(char	**pp)
{
	int	i;

	i = 0;
	if (!pp)
		return (NULL);
	while (pp[i])
	{
		pp[i] = safe_free(pp[i]);
		i++;
	}
	pp = safe_free(pp);
	return (NULL);
}
