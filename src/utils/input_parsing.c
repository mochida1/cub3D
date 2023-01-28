/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:10:32 by viferrei          #+#    #+#             */
/*   Updated: 2023/01/25 17:57:08 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	input_parsing(int argc, char **argv)
{
	char	*suffix;
	int		i;
	
	if (argc > 2)
	{
		printf("error: cub3d must receive only 1 argument\n");
		exit (1);
	}
	suffix = NULL;
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == '.')
		{
			suffix = &argv[1][i];
			printf("%s", suffix);
		}
		if (suffix && ft_strncmp(suffix, ".cub", 4))
		{
			printf("error: input must be a '.cub' file\n");
			exit (1);
		}
		else if (open(argv[1], O_RDONLY) < 0)
		{
			perror("input file");
			exit (1);
		}
		i++;
	}
	return (0);
}
