/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:58:10 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/22 16:08:33 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub_defs.h"

int	get_raw_map_size(t_raw_map *map, char *path_to_map)
{
	int		fd;
	char	*tmp;

	fd = open(path_to_map, O_RDONLY);
	if (fd < 0)
	{
		perror("ERROR(get_raw_map_size)");
		return (1);
	}
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		tmp = safe_free(tmp);
		map->raw_map_size++;
	}
	close(fd);
	return (0);
}

//	Saves each line of the map file in raw_map_data
int	read_map_data(t_raw_map *map, char *path_to_map)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(path_to_map, O_RDONLY);
	map->raw_map_data = ft_calloc(map->raw_map_size + 1, (sizeof (char *)));
	while (1)
	{
		map->raw_map_data[i] = get_next_line(fd);
		if (map->raw_map_data[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	return (0);
}

int	get_raw_map_data(t_raw_map *map, char *path_to_map)
{
	if (get_raw_map_size(map, path_to_map))
	{
		printf("error getting raw map data\n");
		exit (1);
	}
	if (read_map_data(map, path_to_map))
	{
		printf("error reading raw map data\n");
		exit (1);
	}
	if (get_raw_map_settings(map))
	{
		printf("error getting map settings\n");
		exit (1);
	}
	map_disassemble(map);
	return (0);
}

/*
	Returns a pointer to a fully read map;
	It is the caller's responsability to free all allocated memmory afterwards;
	Just use utils_free_map_file(char **ptr);
*/
t_raw_map	*init_map(char *path_to_map)
{
	t_raw_map	*map;
	t_settings	*settings;


	map = ft_calloc(1, sizeof(t_raw_map));
	settings = ft_calloc(1, sizeof(t_settings));
	get_raw_map_data(map, path_to_map);
	get_settings(settings, map->raw_cfg);
	return (map);
}

void	*destroy_map(t_raw_map *map)
{
	map->raw_map_data = free_string_array(map->raw_map_data);
	map->raw_layout = free_string_array(map->raw_layout);
	map = safe_free(map);
	return (NULL);
}
