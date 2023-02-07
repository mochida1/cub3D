/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_map_settings.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:22:52 by viferrei          #+#    #+#             */
/*   Updated: 2023/02/07 19:26:26 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
//	Checks if line is a direction or color setting. If direction, if it's
//	followed by a space and valid path.
*/
int	valid_setting(char *raw_line)
{
	char	**line;
	int		exit_code;

	line = ft_split_spaces(raw_line);
	exit_code = 0;
	if (!ft_strcmp(line[0], "NO") || !ft_strcmp(line[0], "SO")
		|| !ft_strcmp(line[0], "WE") || !ft_strcmp(line[0], "EA"))
	{
		exit_code = 1;
		if (open(line[1], O_RDONLY) < 0)
		{
			printf("Invalid texture path\n");
			exit_code = 0;
		}
	}
	else if (!ft_strcmp(line[0], "F") || !ft_strcmp(line[0], "C"))
		exit_code = 1;
	free_string_array(line);
	return (exit_code);
}

/*
//	Saves line into raw_cfg struct and returns 1 when all settings are saved.
*/
int	save_raw_setting(t_raw_map *map, char *line)
{
	static int	index = 0;
	static int	settings_complete = 0;

	if (settings_complete)
	{
		printf("error: too many settings arguments\n");
		exit (1);
	}
	while (index < 7 && !settings_complete)
	{
		map->raw_cfg[index] = line;
		index++;
		break ;
	}
	if (index == 6)
		settings_complete = 1;
	return (0);
}

/*
// Runs through line spaces and saves the address of the line starting point.
*/
int	jump_spaces(char **line_start, t_raw_map *map, int line)
{
	int	c;

	c = 0;
	while (ft_isspace(map->raw_map_data[line][c]))
		c++;
	if (!(*line_start))
		*line_start = &(map->raw_map_data[line][c]);
	return (c);
}

/*
//	Runs through lines ignoring initial spaces and saves the setting lines into
//	the map->raw_cfg array
*/
int	get_raw_map_settings(t_raw_map *map)
{
	int		line;
	char	*line_start;

	line = 0;
	map->raw_cfg = calloc(7, sizeof(char *));
	while (map->raw_map_data[line])
	{
		line_start = NULL;
		jump_spaces(&line_start, map, line);
		if (line_start[0] == '#' || !line_start[0])
		{
			line++;
			continue ;
		}
		if (valid_setting(line_start))
			save_raw_setting(map, line_start);
		line++;
	}
	return (0);
}
