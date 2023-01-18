/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:22:52 by viferrei          #+#    #+#             */
/*   Updated: 2023/01/17 21:55:55 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	invalid_color(char *line)
{
	/*
	split by commas, check if rgb numbers are valid.
	*/
}

int	invalid_setting(char *raw_line)
{
	char	**line;
	int		exit_code;

	line = ft_split(raw_line, ' ');
	exit_code = 1;
	if (line[0] == "NO" || line[0] == "SO"
		|| line[0] == "WE" || line[0] == "EA")
	{
		exit_code = 0;
		if (open(line[1], O_RDONLY) < 0)
			exit_code = 2;
	}
	else if (line[0] == "F" || line[0] == "C")
	{
		exit_code = 0;
		if (invalid_color(line[1]))
			exit_code = 3;
	}
	free_string_array(line);
	return (exit_code);
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
