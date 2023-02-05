/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:18:59 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/05 16:23:41 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_wall_face(t_mlx *mlx)
{
	if (mlx->cu->ray_dirx < 0 && mlx->cu->ray_diry < 0)
	{
		if (mlx->cu->side == 1)
			return (WALL_NORTH);
		return (WALL_EAST);
	}
	else if (mlx->cu->ray_dirx > 0 && mlx->cu->ray_diry < 0)
	{
		if (mlx->cu->side == 1)
			return (WALL_NORTH);
		return (WALL_WEST);
	}
	else if (mlx->cu->ray_dirx < 0 && mlx->cu->ray_diry > 0)
	{
		if (mlx->cu->side == 1)
			return (WALL_SOUTH);
		return (WALL_EAST);
	}
	else
	{
		if (mlx->cu->side == 1)
			return (WALL_SOUTH);
		return (WALL_WEST);
	}
}

/*
	IMPLEMENTAR!!!
	o máximo de faces que se pode ver é 3.
	Tudo depende da posição do jogador e da posição das paredes;
*/
static int	get_color_from_texture(t_mlx *mlx)
{
	if (mlx->cu->wall_face == WALL_NORTH)
		return (C_RED);
	else if(mlx->cu->wall_face == WALL_SOUTH)
		return (C_LPINK);
	else if(mlx->cu->wall_face == WALL_EAST)
		return (C_YELLOW);
	else if(mlx->cu->wall_face == WALL_WEST)
		return (C_PURP);
	return (0);

	// if (mlx->cu->ray_dirx < 0 && mlx->cu->ray_diry < 0)
	// {
	// 	if (mlx->cu->side == 1)
	// 		return (0x000088);
	// 	return (0x0000ff);
	// }
	// else if (mlx->cu->ray_dirx > 0 && mlx->cu->ray_diry < 0)
	// {
	// 	if (mlx->cu->side == 1)
	// 		return (0x880000);
	// 	return (0xff0000);
	// }
	// else if (mlx->cu->ray_dirx < 0 && mlx->cu->ray_diry > 0)
	// {
	// 	if (mlx->cu->side == 1)
	// 		return (0x888800);
	// 	return (0xffff00);
	// }
	// else
	// {
	// 	if (mlx->cu->side == 1)
	// 		return (0x008800);
	// 	return (0x00ff00);
	// }
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
	mlx->cu->color = C_CYAN; // NEEDS FIX
	count = draw_ceiling(mlx, cube_img, pixel_x, count);
	count = draw_wall(mlx, cube_img, pixel_x, count);
	mlx->cu->color = C_BROWN; // NEEDS FIX
	count = draw_floor(mlx, cube_img, pixel_x, count);
}
