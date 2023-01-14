/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_disassemble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:13:50 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/14 18:31:59 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_defs.h"
#include "cub3d.h"

/*
	Skips to the first line whose 1st nonspace character is 1;
*/
int		iterate_to_map(t_raw_map *map)
{
	int	line;
	int	index;

	line = 0;
	index = 0;
	while (map->raw_map_data[line])
	{
		while (map->raw_map_data[line][0] == '\n' || map->raw_map_data[line][0] == '#')
			line ++;
		while (map->raw_map_data[line][index] == ' ' || map->raw_map_data[line][index] == '\t')
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
unsigned int	get_raw_max_len(t_raw_map *map, int line)
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
unsigned int	get_raw_layout_size(t_raw_map *map, int line)
{
	unsigned int	index;
	int				ret;

	ret = line;
	index = 0;
	while (map->raw_map_data[line])
	{
		if  (map->raw_map_data[line][index] && map->raw_map_data[line][index] != '1')
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
int	init_raw_map_layout(t_raw_map *map, int line)
{
	unsigned int	index;

	index = 0;
	map->raw_layout = ft_calloc(map->raw_layout_size + 1, sizeof(char *));
	while(map->raw_layout_size > index)
	{
		map->raw_layout[index] = ft_strdup(map->raw_map_data[index + line]);
		if (!map->raw_map_data)
			return(1);
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
	printf ("Map starts at line %d\n", line);
	map->raw_layout_size = get_raw_layout_size(map, line);
	printf ("Layoutsize is %d\n", map->raw_layout_size);
	map->raw_map_max_len = get_raw_max_len(map, line);
	printf ("max len size is %d\n", map->raw_map_max_len);
	init_raw_map_layout(map, line);
}

/*
	Splits raw map data loaded in memmory into unparsed configs strings and
	unparsed layout strings
*/
void map_disassemble(t_raw_map *map)
{
	get_map_raw_layout(map);
}
