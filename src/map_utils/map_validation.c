/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:27:57 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/16 20:28:37 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_for_starting(char **raw_map)
{
	int	line;
	int	col;
	int	flag;

	line = 0;
	col = 0;
	flag = 0;
	while (raw_map[line])
	{
		while (raw_map[line][col] && raw_map[line][col] != '\n')
		{
			if (!int_strrchr("NSWE", raw_map[line][col]))
				flag++;
			col++;
		}
		col = 0;
		line++;
	}
	if (flag == 1)
		return (0);
	return (32);
}

int	check_settings(char **raw_cfg)
{
	(void) raw_cfg;
	return (0);
}

/*
	Map validations. Takes some time to be performed because of poor alorithm
	performance. 0 fucks given.
	returns 0 on success and 1 if an error was encountered.
*/
int	check_map(char **raw_map)
{
	int	rc;

	rc = check_first_line(raw_map);
	rc |= check_last_line(raw_map);
	rc |= check_adjacency(raw_map);
	rc |= check_duplicate(raw_map);
	rc |= check_character(raw_map);
	rc |= check_for_starting(raw_map);
	if (rc)
		printf ("ERROR #%d\n", rc);
	return (rc);
}

int	check_raw_data(char **raw_data)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (raw_data[line])
	{
		if (raw_data[line][col] == '#')
		{
			line++;
			continue ;
		}
		while (raw_data[line][col] == ' ')
			col++;
		if (int_strrchr("NSWEFC1\n", raw_data[line][col]))
		{
			printf("ERROR: First character of line in file is invalid!\n");
			printf("\tat line[%d], col[%d], char[%c]\n",
				line, col, raw_data[line][col]);
			return (1);
		}
		col = 0;
		line++;
	}
	return (0);
}

int	validate_map(t_raw_map *map)
{
	int	rc;

	rc = check_raw_data(map->raw_map_data);
	rc |= check_settings(map->raw_map_data);
	rc |= check_map(map->raw_layout);
	if (rc)
	{
		printf("ERROR: Invalid map!\n");
		map = free_raw_map(map);
		exit (1);
	}
	return (0);
}
