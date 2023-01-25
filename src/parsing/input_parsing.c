/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:10:32 by viferrei          #+#    #+#             */
/*   Updated: 2023/01/25 13:17:24 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	input_parsing(int argc, char *argv)
{
	char	*suffix;

	if (argc > 2)
	{
		printf("error: cub3d must receive only 1 argument\n");
		return (1);
	}
	while (argv[1][i])
	{
		if (argv[1][i] == '.')
			suffix = argv[1][i];
		if (ft_strcmp(suffix, ".cub"))
		{
			printf("error: input must be a '.cub' file\n");
			return (1);
		}
		i++;
	}
	return (0);
}
