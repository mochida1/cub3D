/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:22:52 by viferrei          #+#    #+#             */
/*   Updated: 2023/01/19 21:54:05 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
int	invalid_color(char *line)
{
	// split by commas, check if rgb numbers are valid.
}
*/

/*
//	Checks if line is a direction or color setting. If it's followed by a space
//	and a valid link or RGB numbers.
*/
int	invalid_setting(char *raw_line)
{
	char	**line;
	int		exit_code;

	line = ft_split(raw_line, ' '); // CREATE A SPLIT THAT CONSIDER TABS
	exit_code = 1;
	if (!ft_strncmp(raw_line, "NO", 2) || !ft_strncmp(raw_line, "SO", 2)
		|| !ft_strncmp(raw_line, "WE", 2) || !ft_strncmp(raw_line, "EA", 2))
	{
		if (ft_isspace(raw_line[2]))
			exit_code = 0;
		if (open(line[1], O_RDONLY) < 0)
			exit_code = 2;
	}
	else if (!ft_strncmp(line[0], "F", 1) || !ft_strncmp(line[0], "C", 1))
	{
		exit_code = 0;
//		if (invalid_color(line[1]))
//			exit_code = 3;
	}
	free_string_array(line);
	return (exit_code);
}

void	save_raw_setting(t_raw_map *map, char *line)
{
	static int	index = 0;

	while (index < 7)
	{
		map->raw_cfg[index] = line;
		index++;
		break ;
	}
}

/*
//	Runs through lines ignoring initial spaces and saves the setting lines into
//	the map->raw_cfg array
*/
int	get_raw_map_settings(t_raw_map *map)
{
	int		line;
	int		c;
	char	*line_start;

	line = 0;
	map->raw_cfg = calloc(7, sizeof(char *));
	while (map->raw_map_data[line])
	{
		c = 0;
		line_start = NULL;
		while(ft_isspace(map->raw_map_data[line][c]))
			c++;
		if (!line_start)
			line_start = &(map->raw_map_data[line][c]);
		if (line_start[0] == '#' || !line_start[0])
		{
			line++;
			continue ;
		}
		else if (invalid_setting(line_start))
			return (1);
		save_raw_setting(map, line_start);
		line++;
	}
	return (0);
}

int	get_texture(char *texture, char *line)
{
	char	**split_line;

	split_line = ft_split(line, ' ');
	texture = ft_strdup(line);
	free_string_array(split_line);
	return (0);
}

int	get_settings(t_settings *settings, char **raw_cfg)
{
	int	i;

	i = 0;
	while (raw_cfg[i])
	{
		if (!ft_strncmp(raw_cfg[i], "NO", 2))
			get_texture(settings->north_texture, raw_cfg[i]); // should i use &(settings)?
		if (!ft_strncmp(raw_cfg[i], "SO", 2))
			get_texture(settings->south_texture, raw_cfg[i]);
		if (!ft_strncmp(raw_cfg[i], "WE", 2))
			get_texture(settings->west_texture, raw_cfg[i]);
		if (!ft_strncmp(raw_cfg[i], "EA", 2))
			get_texture(settings->east_texture, raw_cfg[i]);
		i++;
	}
	return 0;
}
