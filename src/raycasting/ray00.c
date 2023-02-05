/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:08:09 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/05 10:12:05 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_starting_direction(t_mlx *mlx, char c)
{
	if (c == 'W')
	{
		mlx->cu->dirx = -1;
		mlx->cu->diry = 0;
	}
	if (c == 'S')
	{
		mlx->cu->dirx = 0;
		mlx->cu->diry = 1;
	}
	if (c == 'N')
	{
		mlx->cu->dirx = 1;
		mlx->cu->diry = -1;
	}
	if (c == 'E')
	{
		mlx->cu->dirx = 1;
		mlx->cu->diry = 0;
	}
}

void	get_starting_position(t_mlx *mlx)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (mlx->map->raw_layout[line])
	{
		while (mlx->map->raw_layout[line][col])
		{
			if(!int_strrchr("NSWE", mlx->map->raw_layout[line][col]))
			{
				mlx->cu->posx = col + 0.5;
				mlx->cu->posy = line + 0.5;
				get_starting_direction(mlx, mlx->map->raw_layout[line][col]);
				return ;
			}
			col++;
		}
		col = 0;
		line++;
	}
}

/*
	draws main cube's game image.
*/
void	draw_cu_image(t_mlx *mlx)
{
	int				pixel_x;
	static t_img	*cube_img;

	printf("cube_img_ptr: %p\n", cube_img);
	if (!cube_img)
		cube_img = ft_mlx_get_image_by_label(mlx, "cube");
	pixel_x = 0;
	while (pixel_x < cube_img->w)
	{
		update_map_pos(mlx);
		init_rays(mlx, pixel_x);
		get_rays_dist_side(mlx);
		calculate_line_coords(mlx);
		draw_column(mlx, cube_img, pixel_x);
		pixel_x++;
	}
}

/*
	Updates cube_img image.
*/
void	img_cub(t_mlx *mlx)
{
	update_map_pos(mlx);
	draw_cu_image(mlx);
}

/*
	initializes and puts the first generated image to screen after startup;
*/
int	init_cu(t_mlx *mlx)
{
	mlx->cu = ft_calloc(1, sizeof(t_cube));
	get_starting_position(mlx);
	init_camera(mlx);
	update_map_pos(mlx);
	draw_cu_image(mlx);
	return (0);
}
