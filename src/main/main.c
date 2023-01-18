/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:02:44 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/17 21:36:18 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>

int	main(int argc, char *argv[])
{
	t_raw_map	*map;
	t_mlx		*mlx;

	map = init_map("map.cub");
	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 800, 600, "Janella");
	event_handler(mlx);

	int i = 0;
	while (map->raw_layout[i])
	{
		printf ("%s", map->raw_layout[i]);
		i++;
	}

	mlx_loop(mlx->mlx_ptr);
	map = destroy_map(map);
	(void) argc;
	(void) argv;
}
