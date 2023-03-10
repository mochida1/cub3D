/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:02:44 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/12 16:46:25 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>
#include "test.h"

void	init_images(t_mlx *mlx, t_raw_map *map)
{
	mlx->tx = init_textures(mlx);
	ft_mlx_init_image(mlx, WINDOW_W, WINDOW_H, "cube");
	ft_mlx_init_image(mlx, (map->raw_map_max_len - 1) * 2, \
		map->raw_layout_size * 2, "minimap");
	ft_mlx_init_image(mlx, MM_SCALE, MM_SCALE, "miniplayer");
	init_cu(mlx);
	img_minimap(ft_mlx_get_image_by_label(mlx, "minimap"), map);
	img_miniplayer(ft_mlx_get_image_by_label(mlx, "miniplayer"), \
		mlx->cu->posx, mlx->cu->posy);
	img_cub(mlx);
}

int	main(int argc, char *argv[])
{
	t_raw_map	*map;
	t_mlx		*mlx;

	input_parsing(argc, argv);
	map = init_map(argv[1]);
	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WINDOW_W, WINDOW_H, "Janella");
	mlx->map = map;
	get_settings(mlx, map->raw_cfg);
	init_images(mlx, map);
	event_handler(mlx);
	render_images(mlx);
	mlx_loop(mlx->mlx_ptr);
	map = destroy_map(map);
	mlx->tx = destroy_tx(mlx);
}
