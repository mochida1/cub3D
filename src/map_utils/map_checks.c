/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:50:26 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/28 16:57:53 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Checks every adjacent tile for valid characters.
	somehow works fine without accessing bad data /shrug.
*/
static int	invalid_adj(char **raw_map, int line, int col)
{
	char	*valid;
	int		rc;

	valid = "10NSWE";
	rc = int_strrchr(valid, raw_map[line -1][col]);
	rc |= int_strrchr(valid, raw_map[line +1][col]);
	rc |= int_strrchr(valid, raw_map[line][col + 1]);
	if (col != 0)
		rc |= int_strrchr(valid, raw_map[line][col - 1]);
	if (rc)
	{
		printf("ERROR: adjacency check failed at ");
		printf("line [%d], col [%d]\n", line, col);
	}
	return (rc);
}

/*
	Core of map parsing. Every walkable tile must be adjacent and enclosed by
	either a wall or another walkable tile. This iterates trough them, and calls
	for a function that verifies it's neighbours.
*/
int	check_adjacency(char **raw_map)
{
	static int	line;
	static int	col;

	while (raw_map[line])
	{
		while (raw_map[line][col])
		{
			if (ft_strrchr("0NSWE", raw_map[line][col]))
				if (invalid_adj(raw_map, line, col))
					return (1);
			col++;
		}
		col = 0;
		line ++;
	}
	return (0);
}

/*
	checks if every character contained in the map is valid.
*/
int	check_character(char **raw_map)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (raw_map[line])
	{
		while (raw_map[line][col])
		{
			if (int_strrchr("NSWE01 \n", raw_map[line][col]))
			{
				printf("ERROR: Invalid character found at line[%d] ", line);
				printf("col[%d]: '%c'\n", col, raw_map[line][col]);
				return (1);
			}
			col++;
		}
		col = 0;
		line++;
	}
	return (0);
}

/*
	Checks for duplicated starting positions.
*/
int	check_duplicate(char **raw_map)
{
	int	line;
	int	col;
	int	start_pos;

	line = 0;
	col = 0;
	start_pos = 0;
	while (raw_map[line])
	{
		while (raw_map[line][col])
		{
			if (start_pos == 1 && !int_strrchr("NSWE", raw_map[line][col]))
			{
				printf("ERROR: duplicated starting position at line [");
				printf("%d], col[%d]: %c\n", line, col, raw_map[line][col]);
				return (1);
			}
			if (start_pos == 0 && !int_strrchr("NSWE", raw_map[line][col]))
				start_pos = 1;
			col++;
		}
		col = 0;
		line++;
	}
	return (0);
}
