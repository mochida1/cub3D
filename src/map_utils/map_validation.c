/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:27:57 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/27 21:50:27 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_space_or_wall(char c, int line, int col)
{
	if (c != '1')
	{
		if(c != ' ')
		{
			printf ("Found invalid character found at line [%d]: ", line);
			printf ("column[%d]: '%c'\n", col, c);
			return (1);
		}
	}
	return (0);
}

int	check_first_line(char **map)
{
	int	col;

	col = 0;
	while (map[0][col] && map[0][col] != '\n')
	{
		if (is_space_or_wall(map[0][col], 0, col))
			return (1);
		col++;
	}
	return (0);
}
int check_last_line(char **map)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (map[line])
		line++;
	while (map[line - 1][col] && map[line - 1][col] != '\n')
	{
		if (is_space_or_wall(map[line - 1][col], line, col))
			return (1);
		col++;
	}
	return (0);
}
int	check_settings(char **raw_cfg)
{
	(void) raw_cfg;
	return (0);
}

int	check_map(char **raw_map)
{
	int	rc;

	rc = check_first_line(raw_map);
	rc |= check_last_line(raw_map);

	return (rc);
}

int	validate_map(t_raw_map *map)
{
	int	rc;

	rc = check_settings(map->raw_map_data);
	rc |= check_map(map->raw_layout);
	if (rc)
	{
		printf("ERROR: Invalid map!\n");
		map = free_raw_map(map);
		exit (1);
	}
	return (0);
}
