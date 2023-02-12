/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:18:59 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/11 21:54:47 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Draws the ceiling and sets count to start drawing the wall.
*/
static int	draw_ceiling(t_mlx *mlx, t_img *cube_img, int pixel_x, int count)
{
	while (count < mlx->cu->wall_start)
	{
		ft_mlx_putpix(pixel_x, count, mlx->cu->color, cube_img);
		count++;
	}
	return (count);
}

/*
	effectivelly draws the walls on the data array of the image;
*/
static int	draw_wall(t_mlx *mlx, t_img *cube_img, int pixel_x, int count)
{
	mlx->cu->wall_face = get_wall_face(mlx);
	mlx->cu->tx_x = get_tx_x(mlx);
	set_tx_y(mlx);
	while (count < mlx->cu->wall_end)
	{
		mlx->cu->color = get_color_from_texture(mlx);
		mlx->tx[mlx->cu->wall_face].position
			+= mlx->tx[mlx->cu->wall_face].step_size;
		ft_mlx_putpix(pixel_x, count, mlx->cu->color, cube_img);
		count++;
	}
	return (count);
}

/*
	continues to draw the floor after drawing the walls;
*/
static int	draw_floor(t_mlx *mlx, t_img *cube_img, int pixel_x, int count)
{
	while (count < cube_img->h - 1)
	{
		ft_mlx_putpix(pixel_x, count, mlx->cu->color, cube_img);
		count++;
	}
	return (count);
}

/*
	writes a single column of the screen with all relevant data.
*/
void	draw_column(t_mlx *mlx, t_img *cube_img, int pixel_x)
{
	int	count;

	count = 0;
	mlx->cu->color = create_single_rgb(mlx->settings->ceiling_color[0], \
		mlx->settings->ceiling_color[1], mlx->settings->ceiling_color[2]);
	count = draw_ceiling(mlx, cube_img, pixel_x, count);
	count = draw_wall(mlx, cube_img, pixel_x, count);
	mlx->cu->color = create_single_rgb(mlx->settings->floor_color[0], \
		mlx->settings->floor_color[1], mlx->settings->floor_color[2]);
	count = draw_floor(mlx, cube_img, pixel_x, count);
}
