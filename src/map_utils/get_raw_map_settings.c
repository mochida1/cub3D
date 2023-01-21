/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_map_settings.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:22:52 by viferrei          #+#    #+#             */
/*   Updated: 2023/01/21 18:07:17 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
//	Checks if line is a direction or color setting. If direction, if it's
//	followed by a space and valid path.
*/
int	invalid_setting(char *raw_line)
{
	char	**line;
	int		exit_code;

	line = ft_split_spaces(raw_line);
	exit_code = 1;
	if (!ft_strcmp(line[0], "NO") || !ft_strcmp(line[0], "SO")
		|| !ft_strcmp(line[0], "WE") || !ft_strcmp(line[0], "EA"))
	{
		exit_code = 0;
		if (open(line[1], O_RDONLY) < 0)
		{
			printf("Invalid texture path\n");
			exit_code = 2;
		}
	}
	else if (!ft_strcmp(line[0], "F") || !ft_strcmp(line[0], "C"))
		exit_code = 0;
	free_string_array(line);
	return (exit_code);
}

/*
//	Saves line into raw_cfg struct and returns 1 when all settings are saved.
*/
int	save_raw_setting(t_raw_map *map, char *line)
{
	static int	index = 0;

	while (index < 7)
	{
		map->raw_cfg[index] = line;
		index++;
		break ;
	}
	if (index == 6)
		return (1);
	return (0);
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
		if (save_raw_setting(map, line_start))
			break ;
		line++;
	}
	return (0);
}

int	get_texture(char **texture, char *line)
{
	char	**split_line;

	split_line = ft_split_spaces(line);
	*texture = ft_strdup(split_line[1]);
	free_string_array(split_line);
	return (0);
}

int	invalid_color(char **split_line)
{
	int	i;

	i = 1;
	while (split_line[i])
	{
		if (ft_atoi(split_line[i]) < 0 || ft_atoi(split_line[i]) > 255)
		{
			printf("Invalid RGB number\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	get_color(int *color, char *line)
{
	int	i;
	char	**split_line;

	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			line[i] = ' ';
		i++;
	}
	split_line = ft_split_spaces(line);
	if (invalid_color(split_line))
		return (1);
	color[0] = ft_atoi(split_line[1]);
	color[1] = ft_atoi(split_line[2]);
	color[2] = ft_atoi(split_line[3]);
	return (0);
}

int	get_settings(t_settings *settings, char **raw_cfg)
{
	int	i;
	int	exit_code;

	i = 0;
	exit_code = 0;
	while (raw_cfg[i])
	{
		if (!ft_strncmp(raw_cfg[i], "NO", 2))
			get_texture(&settings->north_texture, raw_cfg[i]);
		if (!ft_strncmp(raw_cfg[i], "SO", 2))
			get_texture(&settings->south_texture, raw_cfg[i]);
		if (!ft_strncmp(raw_cfg[i], "WE", 2))
			get_texture(&settings->west_texture, raw_cfg[i]);
		if (!ft_strncmp(raw_cfg[i], "EA", 2))
			get_texture(&settings->east_texture, raw_cfg[i]);
		if (!ft_strncmp(raw_cfg[i], "F", 1))
			exit_code = get_color(settings->floor_color, raw_cfg[i]);
		if (!ft_strncmp(raw_cfg[i], "C", 1))
			exit_code = get_color(settings->ceiling_color, raw_cfg[i]);
		i++;
	}
	return (exit_code);
}
