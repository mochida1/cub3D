/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:18:59 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/06 20:14:40 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	IMPLEMENTAR!!!
*/
static int	get_color_from_texture(t_mlx *mlx)
{
	if (mlx->cu->wall_face == WALL_NORTH)
		return (C_RED);
	else if (mlx->cu->wall_face == WALL_SOUTH)
		return (C_LPINK);
	else if (mlx->cu->wall_face == WALL_EAST)
		return (C_YELLOW);
	else if (mlx->cu->wall_face == WALL_WEST)
		return (C_PURP);
	return (0);
}

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
	while (count < mlx->cu->wall_end)
	{
		mlx->cu->wall_face = get_wall_face(mlx);
		mlx->cu->color = get_color_from_texture(mlx);
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
