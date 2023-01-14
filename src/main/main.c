/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:02:44 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/14 18:33:32 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_raw_map	*map;

	map = init_map("map.cub");

	int i;
	i=0;
	while (map->raw_layout[i])
	{
		printf("%s", map->raw_layout[i]);
		i++;
	}

	map = detroy_map(map);
	//desabilita warnings de unused variables
	(void) argc;
	(void) argv;
}
