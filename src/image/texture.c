/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:04:40 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/11 15:06:48 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Destroys all texture images, frees mlx->tx;
	must be called before destroying MLX struct.
*/
void	*destroy_tx(t_mlx *mlx)
{
	int	index;

	index = 0;
	while(index<4)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->tx[index].tx_img_ptr);
		index++;
	}
	mlx->tx = safe_free(mlx->tx);
	return (0);
}

/*
	initializes all 4 textures from settings;
	must be destroyed later by destroy_tx(mlx);
*/
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
