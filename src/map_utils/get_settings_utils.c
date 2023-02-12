/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_settings_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:40:29 by viferrei          #+#    #+#             */
/*   Updated: 2023/02/12 15:14:31 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	no_xpm_files_found(t_settings *settings)
{
	int	fd;
	int	ret;

	ret = 0;
	fd = open(settings->north_texture, O_RDONLY);
	if (fd < 0)
		ret |= printf("Error: texture path - %s\n", settings->north_texture);
	close(fd);
	fd = open(settings->south_texture, O_RDONLY);
	if (fd < 0)
		ret |= printf("Error: texture path - %s\n", settings->south_texture);
	close(fd);
	fd = open(settings->east_texture, O_RDONLY);
	if (fd < 0)
		ret |= printf("Error: texture path - %s\n", settings->east_texture);
	close(fd);
	fd = open(settings->west_texture, O_RDONLY);
	if (fd < 0)
		ret |= printf("Error: texture path - %s\n", settings->west_texture);
	close(fd);
	return (ret);
}

int	empty_setting(t_settings *settings)
{
	int	exit_code;
	int	i;

	exit_code = 0;
	i = 0;
	if (!settings->north_texture || !settings->south_texture
		|| !settings->west_texture || !settings->east_texture)
		exit_code = 1;
	while (i < 3)
	{
		if (settings->floor_color[i] == -1 || settings->ceiling_color[i] == -1)
			exit_code = 1;
		i++;
	}
	if (exit_code)
		printf("error: missing color or texture setting.\n");
	return (exit_code);
}

/*
// Checks the number of settings elements or if any of them are empty.
*/
int	check_settings_nb(t_settings *settings, int settings_count)
{
	int	exit_code;

	exit_code = 0;
	if (settings_count != 6)
	{
		printf("error: wrong number of settings in .cub file\n");
		exit_code = 1;
	}
	if (empty_setting(settings))
		exit_code = 1;
	if (no_xpm_files_found(settings))
		exit_code = 1;
	return (exit_code);
}

/*
// Changes color values to -1 to later check if all values were assigned.
*/
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

/*
//	Returns RGB numbers as a single int
*/
int	create_single_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
