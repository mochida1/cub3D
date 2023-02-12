/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:51:36 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/11 21:57:09 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	sets initial position and step size for iteration on the
	column of a texture;
*/
void	set_tx_y(t_mlx *mlx)
{
	mlx->tx[mlx->cu->wall_face].step_size = 1.0
		* mlx->tx[mlx->cu->wall_face].h / mlx->cu->wall_h;
	mlx->tx[mlx->cu->wall_face].position = 0;
	if (mlx->cu->wall_h > WINDOW_H)
		mlx->tx[mlx->cu->wall_face].position = (mlx->cu->wall_h - WINDOW_H) / 2
			* mlx->tx[mlx->cu->wall_face].step_size;
}

int	get_color_from_data(char *ptr)
{
	char	rgba[4];
	int		*ret;

	rgba[3] = 0x00;
	rgba[2] = ptr[2];
	rgba[1] = ptr[1];
	rgba[0] = ptr[0];
	ret = (int *) rgba;
	return (*ret);
}

/*
	Makes a shitload of weird calculations;
	makes sure tx_y isn't bigger than wall's height in order not to segfault.
	gets color from the texture.
*/
int	get_color_from_texture(t_mlx *mlx)
{
	char	*ptr;
	int		color;
	int		tx_y;

	tx_y = (int)mlx->tx[mlx->cu->wall_face].position;
	tx_y = (int)mlx->tx[mlx->cu->wall_face].position
		& (mlx->tx[mlx->cu->wall_face].h - 1);
	ptr = mlx->tx[mlx->cu->wall_face].data
		+ (tx_y * mlx->tx[mlx->cu->wall_face].sz_line + mlx->cu->tx_x
			* (mlx->tx[mlx->cu->wall_face].bpp / 8));
	color = get_color_from_data(ptr);
	return (color);
}

/*
	returns the texture column to start drawing the wall.
*/
double	get_wall_x(t_mlx *mlx)
{
	double	wall_hit_x;

	if (mlx->cu->side == 0)
		wall_hit_x = mlx->cu->posy + mlx->cu->perp_dist * mlx->cu->ray_diry;
	else
		wall_hit_x = mlx->cu->posx + mlx->cu->perp_dist * mlx->cu->ray_dirx;
	wall_hit_x -= (int) wall_hit_x;
	return (wall_hit_x);
}

/*
	returns starting x coordinate of the texture;
*/
int	get_tx_x(t_mlx *mlx)
{
	int		ret;
	double	wall_hit_x;

	wall_hit_x = get_wall_x(mlx);
	ret = (int)(wall_hit_x * (double) mlx->tx[mlx->cu->wall_face].w);
	if (mlx->cu->side == 0 && mlx->cu->ray_dirx > 0)
		ret = mlx->tx[mlx->cu->wall_face].w - ret - 1;
	if (mlx->cu->side == 1 && mlx->cu->ray_diry < 0)
		ret = mlx->tx[mlx->cu->wall_face].w - ret - 1;
	return (ret);
}
