/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:02:44 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/11 14:56:54 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>
#include "test.h"

t_tx	*init_textures(t_mlx *mlx)
{
	t_tx	*tx;

	tx = ft_calloc(4, sizeof(t_tx));
	printf("north texture: %s\n", mlx->settings->north_texture);
	tx[NORTH].tx_img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			mlx->settings->north_texture, &tx[NORTH].w, &tx[NORTH].h);
	tx[SOUTH].tx_img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			mlx->settings->south_texture, &tx[SOUTH].w, &tx[SOUTH].h);
	tx[WEST].tx_img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			mlx->settings->west_texture, &tx[WEST].w, &tx[WEST].h);
	tx[EAST].tx_img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			mlx->settings->east_texture, &tx[EAST].w, &tx[EAST].h);
	tx[NORTH].data = mlx_get_data_addr(tx[NORTH].tx_img_ptr, &tx[NORTH].bpp,
			&tx[NORTH].sz_line, &tx[NORTH].endian);
	tx[SOUTH].data = mlx_get_data_addr(tx[SOUTH].tx_img_ptr, &tx[SOUTH].bpp,
			&tx[SOUTH].sz_line, &tx[SOUTH].endian);
	tx[WEST].data = mlx_get_data_addr(tx[WEST].tx_img_ptr, &tx[WEST].bpp,
			&tx[WEST].sz_line, &tx[WEST].endian);
	tx[EAST].data = mlx_get_data_addr(tx[EAST].tx_img_ptr, &tx[EAST].bpp,
			&tx[EAST].sz_line, &tx[EAST].endian);
	return (tx);
}

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
	t_settings	*settings;
	int			y;

	input_parsing(argc, argv);
	map = init_map("map.cub");
	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WINDOW_W, WINDOW_H, "Janella");
	mlx->map = map;
	settings = ft_calloc(1, sizeof(t_settings));
	get_settings(settings, map->raw_cfg);
	mlx->settings = settings;
	y = 0;
	while (mlx->map->raw_layout[y] != 0)
	{
		printf("%s", mlx->map->raw_layout[y]);
		y++;
	}
	init_images(mlx, map);
	event_handler(mlx);
	render_images(mlx);
	mlx_loop(mlx->mlx_ptr);
	map = destroy_map(map);
}
