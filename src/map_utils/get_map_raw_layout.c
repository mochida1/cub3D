/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_raw_layout.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:53:48 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/17 22:00:50 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub_defs.h"

/*
	Skips to the first line whose 1st nonspace character is 1;
*/
static int	iterate_to_map(t_raw_map *map)
{
	int	line;
	int	index;

	line = 0;
	index = 0;
	while (map->raw_map_data[line])
	{
		while (map->raw_map_data[line][0] == '\n' ||
				map->raw_map_data[line][0] == '#')
			line ++;
		while (map->raw_map_data[line][index] == ' ' ||
				map->raw_map_data[line][index] == '\t')
			index++;
		if (map->raw_map_data[line][index] == '1')
			return (line);
		line++;
		index = 0;
	}
	return (-1);
}

/*
	Returns the largest line of a map layout (trailing spaces included);
*/
static unsigned int	get_raw_max_len(t_raw_map *map, int line)
{
	unsigned int	index;
	unsigned int	ret;

	ret = 0;
	while (map->raw_map_data[line])
	{
		index = 0;
		while (map->raw_map_data[line][index])
			index++;
		if (index > ret)
			ret = index;
		line++;
	}
	return (ret);
}

/*
	Returns the map layout size(height).
*/
static unsigned int	get_raw_layout_size(t_raw_map *map, int line)
{
	unsigned int	index;
	int				ret;

	ret = line;
	index = 0;
	while (map->raw_map_data[line])
	{
		if (map->raw_map_data[line][index] && map->raw_map_data[line][index]
			!= '1')
			index++;
		else
		{
			line++;
			index = 0;
		}
	}
	return (line - ret);
}

/*
	Inits the raw map information.
*/
static int	init_raw_map_layout(t_raw_map *map, int line)
{
	unsigned int	index;

	index = 0;
	map->raw_layout = ft_calloc(map->raw_layout_size + 1, sizeof(char *));
	while (map->raw_layout_size > index)
	{
		if (map->raw_map_data[index + line][0] == '#')
		{
			index++;
			continue ;
		}
		if (map->raw_map_data[index + line][0] == '\n')
		{
			index++;
			continue ;
		}
		map->raw_layout[index] = ft_strdup(map->raw_map_data[index + line]);
		if (!map->raw_map_data)
			return (1);
		index++;
	}
	return (0);
}

/*
	Gets unparsed raw map layout from raw map data
*/
void	get_map_raw_layout(t_raw_map *map)
{
	int	line;

	line = (int) iterate_to_map(map);
	map->raw_layout_size = get_raw_layout_size(map, line);
	map->raw_map_max_len = get_raw_max_len(map, line);
	init_raw_map_layout(map, line);
}
