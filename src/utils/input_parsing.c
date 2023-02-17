/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:10:32 by viferrei          #+#    #+#             */
/*   Updated: 2023/02/16 21:51:20 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	validate_argc(int argc)
{
	if (argc > 2)
	{
		printf("ERROR: cub3d must receive only 1 argument\n");
		exit (1);
	}
	if (argc == 1)
	{
		printf("ERROR: cub3d must receive only 1 argument\n");
		exit (1);
	}
}

static void	validate_file(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		perror("input file");
		exit (1);
	}
	close(fd);
}

int	input_parsing(int argc, char **argv)
{
	char	*suffix;
	int		i;

	validate_argc(argc);
	suffix = NULL;
	i = 0;

	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4))
	{
		printf("error: input must be a '.cub' file\n");
		exit (1);
	}
	validate_file(argv[1]);
	return (0);
}
