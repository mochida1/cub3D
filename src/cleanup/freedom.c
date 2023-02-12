/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:50:14 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/12 16:39:33 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_settings(t_mlx *mlx)
{
	mlx->settings->north_texture = safe_free(mlx->settings->north_texture);
	mlx->settings->north_texture = safe_free(mlx->settings->south_texture);
	mlx->settings->north_texture = safe_free(mlx->settings->east_texture);
	mlx->settings->north_texture = safe_free(mlx->settings->west_texture);
	mlx->settings = safe_free(mlx->settings);
}

void	destroy_img_list(t_mlx *mlx)
{
	t_img	*tmp;
	t_img	*freeme;

	tmp = mlx->img_list_head;
	freeme = tmp;
	while (freeme)
	{
		tmp = tmp->next;
		mlx_destroy_image(mlx->mlx_ptr, freeme->img_ptr);
		freeme = safe_free(freeme);
		freeme = tmp;
	}
}

void	destroy_cu(t_mlx *mlx)
{
	mlx->cu = safe_free(mlx->cu);
}

void	destroy_mlx(t_mlx *mlx)
{
	destroy_map(mlx->map);
	destroy_tx(mlx);
	destroy_img_list(mlx);
	destroy_settings(mlx);
	destroy_cu(mlx);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	mlx->mlx_ptr = safe_free(mlx->mlx_ptr);
	mlx = safe_free(mlx);
}

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
