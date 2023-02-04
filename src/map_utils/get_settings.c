/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:21:55 by viferrei          #+#    #+#             */
/*   Updated: 2023/02/04 18:53:56 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
//	Checks if color numbers are inbetween 0 and 255. Does not check if it's a
//	non-decimal number.
*/
int	invalid_color(char **split_line)
{
	int	i;

	i = 1;
	while (split_line[i])
	{
		if (ft_atoi(split_line[i]) < 0 || ft_atoi(split_line[i]) > 255)
			return (1);
		i++;
	}
	return (0);
}

/*
//	Replaces commas with spaces and splits the line into setting and color
//	numbers.
*/
int	get_color(int *color, char *line)
{
	int		i;
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
	{
		free_string_array(split_line);
		printf("error: invalid RGB color\n");
		exit(1);
	}
	color[0] = ft_atoi(split_line[1]);
	color[1] = ft_atoi(split_line[2]);
	color[2] = ft_atoi(split_line[3]);
	free_string_array(split_line);
	return (1);
}

int	get_texture(char **texture, char *line)
{
	char	**split_line;

	split_line = ft_split_spaces(line);
	*texture = ft_strdup(split_line[1]);
	free_string_array(split_line);
	return (1);
}

/*
// Checks if any element of the settings struct is empty.
*/
int	check_settings(t_settings *settings, int settings_count)
{
	int exit_code;
	int i;

	exit_code = 0;
	i = 0;

	if (!settings->north_texture || !settings->south_texture
		|| !settings->west_texture || !settings->east_texture)
	{
		printf("error: missing texture setting\n");
		exit_code = 1;
	}
	while (i < 3)
	{
		if (settings->floor_color[i] == -1 || settings->ceiling_color[i] == -1)
		{
			printf("error: missing color setting\n");
			exit_code = 1;
		}
	}
	return (exit_code);
}

/*
// Changes color values to -1 to later check if all values were assigned.
*/
void settings_loop(t_settings *settings, char *raw_cfg, int *settings_count)
{
	if (!ft_strncmp(raw_cfg, "NO", 2))
		*settings_count += get_texture(&settings->north_texture, raw_cfg);
	if (!ft_strncmp(raw_cfg, "SO", 2))
		*settings_count += get_texture(&settings->south_texture, raw_cfg);
	if (!ft_strncmp(raw_cfg, "WE", 2))
		*settings_count += get_texture(&settings->west_texture, raw_cfg);
	if (!ft_strncmp(raw_cfg, "EA", 2))
		*settings_count += get_texture(&settings->east_texture, raw_cfg);
	if (!ft_strncmp(raw_cfg, "F", 1))
		*settings_count += get_color(settings->floor_color, raw_cfg);
	if (!ft_strncmp(raw_cfg, "C", 1))
		*settings_count += get_color(settings->ceiling_color, raw_cfg);
}
int	init_colors(t_settings *settings)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		settings->floor_color[i] = -1;
		settings->ceiling_color[i] = -1;
		i++;
	}
	return (0);
}

void settings_loop(t_settings *settings, char *raw_cfg, int *settings_count)
{
	if (!ft_strncmp(raw_cfg, "NO", 2))
		*settings_count += get_texture(&settings->north_texture, raw_cfg);
	if (!ft_strncmp(raw_cfg, "SO", 2))
		*settings_count += get_texture(&settings->south_texture, raw_cfg);
	if (!ft_strncmp(raw_cfg, "WE", 2))
		*settings_count += get_texture(&settings->west_texture, raw_cfg);
	if (!ft_strncmp(raw_cfg, "EA", 2))
		*settings_count += get_texture(&settings->east_texture, raw_cfg);
	if (!ft_strncmp(raw_cfg, "F", 1))
		*settings_count += get_color(settings->floor_color, raw_cfg);
	if (!ft_strncmp(raw_cfg, "C", 1))
		*settings_count += get_color(settings->ceiling_color, raw_cfg);
}

int	get_settings(t_settings *settings, char **raw_cfg)
{
	int	i;
	int	settings_count;

	i = 0;
	settings_count = 0;
	init_colors(settings);
	while (raw_cfg[i])
	{
		settings_loop(settings, raw_cfg[i], &settings_count);
		i++;
	}
	if (check_settings(settings, settings_count))
		exit (1);
	return (0);
}
