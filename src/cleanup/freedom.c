/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:50:14 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/27 21:30:06 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*free_raw_map(t_raw_map *map)
{
	map->raw_map_data = free_string_array(map->raw_map_data);
	map->raw_cfg = safe_free(map->raw_cfg);
	map->raw_layout = free_string_array(map->raw_layout);
	map->raw_map_size = 0;
	map->raw_layout_size = 0;
	map->raw_map_max_len = 0;
	map = safe_free(map);
	return (NULL);
}
