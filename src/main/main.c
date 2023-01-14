/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:02:44 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/14 20:52:24 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>

int	main(int argc, char *argv[])
{
	t_raw_map	*map;
	t_mlx		*mlx;

	map = init_map("map.cub");
	map = destroy_map(map);
	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->ctx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->ctx_ptr, 200, 200, "Janella");

	while (1)
		sleep(1);
	(void) argc;
	(void) argv;
}
