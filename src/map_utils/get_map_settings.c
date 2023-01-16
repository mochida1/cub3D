/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:22:52 by viferrei          #+#    #+#             */
/*   Updated: 2023/01/16 20:23:03 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Returns 1 if the line begins with something other than NO, SO, WE, EA, F or C
int	invalid_setting(char *line)
{
	if (ft_strncmp(line, "NO ", 3) && ft_strncmp(line, "SO ", 3)
		&& ft_strncmp(line, "WE ", 3) && ft_strncmp(line, "EA ", 3)
		&& ft_strncmp(line, "F ", 2) && ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}

void	save_raw_setting(t_raw_map *map, char *line)
{
	static int	i = 0;
	while (i < 7)
	{
		map->raw_cfg[i] = line;
		i++;
	}
}

// Saves only the 6 settings lines into the array
int	get_raw_map_settings(t_raw_map *map)
{
	int	line;
	int	c;

	line = 0;
	map->raw_cfg = calloc(7, sizeof(char *));
	while (map->raw_map_data[line])
	{
		c = 0;
		while(map->raw_map_data[line][c])
		{
			while(ft_isspace(map->raw_map_data[line][c]))
				c++;
			if (map->raw_map_data[line][c] == '#')
				break ;
			else if (invalid_setting(map->raw_map_data[line][c]))
				return (1);
			save_raw_setting(map, map->raw_map_data[line][c]); // is this the address to the char or the char itself?
			c++;
		}
		line++;
	}
	return (0);
}
