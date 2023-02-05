/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:14:13 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/05 10:17:06 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	initialies camera values;
*/
void	init_camera(t_mlx *mlx)
{
	mlx->cu->planex = 0;
	mlx->cu->planey = PLANE_DIST;
}

/*
	updates map position before starting raycasting a screen;
	MUST be called before draw_cu_image();
*/
void update_map_pos(t_mlx *mlx)
{
	mlx->cu->mapx = (int) mlx->cu->posx;
	mlx->cu->mapy = (int) mlx->cu->posy;
}

/*
	sets ray starting positions directions
	and from wich tile we're sending it from.
*/
void	init_rays(t_mlx *mlx, int pixel_x)
{
	static t_img	*cube_img;

	if (!cube_img)
		cube_img = ft_mlx_get_image_by_label(mlx, "cube");
	mlx->cu->camera = 2 * pixel_x / (double) cube_img->w - 1;
	mlx->cu->ray_dirx = mlx->cu->dirx + mlx->cu->planex * mlx->cu->camera;
	mlx->cu->ray_diry = mlx->cu->diry + mlx->cu->planey * mlx->cu->camera;
}

/*
	Calculates where to start and drawing the columns to form walls.
*/
void	calculate_line_coords(t_mlx *mlx)
{
	static t_img	*cube_img;

	if (!cube_img)
		cube_img = ft_mlx_get_image_by_label(mlx, "cube");
	mlx->cu->wall_h = (int) (cube_img->h / mlx->cu->perp_dist);
	mlx->cu->wall_start = -mlx->cu->wall_h / 2 + cube_img->h / 2;
	if (mlx->cu->wall_start < 0)
		mlx->cu->wall_start = 0;
	mlx->cu->wall_end = mlx->cu->wall_h / 2 + cube_img->h / 2;
	if (mlx->cu->wall_end >= cube_img->h)
		mlx->cu->wall_end = cube_img->h - 1;
}

/*
	Gets perpendicular distance from camera plane's vector to the wall.
*/
void	get_rays_dist_side(t_mlx *mlx)
{
	if (mlx->cu->ray_dirx == 0)
		mlx->cu->delta_x = 1e30;
	else
		mlx->cu->delta_x = fabs(1 / mlx->cu->ray_dirx);
	if (mlx->cu->ray_diry == 0)
		mlx->cu->delta_y = 1e30;
	else
		mlx->cu->delta_y = fabs(1 / mlx->cu->ray_diry);
	setup_step_direction(mlx);
	move_ray(mlx);
}
