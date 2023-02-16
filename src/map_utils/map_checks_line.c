/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:53:33 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/16 20:19:04 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	First and last lines should only be compose of a space or a wall.
*/
static int	is_space_or_wall(char c, int line, int col)
{
	if (c != '1')
	{
		if (c != ' ')
		{
			printf ("Found invalid character found at line [%d]: ", line);
			printf ("column[%d]: '%c'\n", col, c);
			return (1);
		}
	}
	return (0);
}

/*
	Checks if first line is composed of only wall tiles.
*/
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

/*
	Checks if last line is composed of only wall tiles.
*/
int	check_last_line(char **map)
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
			return (2);
		col++;
	}
	return (0);
}
