/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:21:55 by viferrei          #+#    #+#             */
/*   Updated: 2023/01/21 18:26:37 by viferrei         ###   ########.fr       */
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
		{
			printf("Invalid RGB number\n");
			return (1);
		}
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
		return (1);
	color[0] = ft_atoi(split_line[1]);
	color[1] = ft_atoi(split_line[2]);
	color[2] = ft_atoi(split_line[3]);
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
