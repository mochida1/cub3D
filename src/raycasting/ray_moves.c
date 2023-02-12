/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:22:27 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/12 18:53:25 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	setup_ray_x_dir(t_mlx *mlx)
{
	if (mlx->cu->ray_dirx < 0)
	{
		mlx->cu->stepx = -1;
		mlx->cu->side_distx = (mlx->cu->posx - mlx->cu->mapx)
			* mlx->cu->delta_x;
	}
	else
	{
		mlx->cu->stepx = 1;
		mlx->cu->side_distx = (mlx->cu->mapx + 1 - mlx->cu->posx)
			* mlx->cu->delta_x;
	}
}

static void	setup_ray_y_dir(t_mlx *mlx)
{
	if (mlx->cu->ray_diry < 0)
	{
		mlx->cu->stepy = -1;
		mlx->cu->side_disty = (mlx->cu->posy - mlx->cu->mapy)
			* mlx->cu->delta_y;
	}
	else
	{
		mlx->cu->stepy = 1;
		mlx->cu->side_disty = (mlx->cu->mapy + 1 - mlx->cu->posy)
			* mlx->cu->delta_y;
	}
}

/*
	Sets ray directions according to player position and direction;
*/
void	setup_step_direction(t_mlx *mlx)
{
	setup_ray_x_dir(mlx);
	setup_ray_y_dir(mlx);
}

/*
	checks wether a wall was hit,
	if it was, calculates the ray's distance to the plane's pixel;
*/
static int	is_wall_hit(t_mlx *mlx)
{
	int	wall;

	wall = 0;
	if (mlx->cu->mapx < 0)
	{
		printf("mapX < 0: something went bad!\n");
		destroy_mlx(mlx);
		exit (1);
	}
	if (mlx->cu->mapy < 0)
	{
		printf("mapy < 0: something went bad!\n");
		destroy_mlx(mlx);
		exit (1);
	}
	if (mlx->map->raw_layout[(int) mlx->cu->mapy][(int) mlx->cu->mapx] == '1')
		wall = 1;
	if (mlx->cu->side == 0)
		mlx->cu->perp_dist = (mlx->cu->side_distx - mlx->cu->delta_x);
	else
		mlx->cu->perp_dist = (mlx->cu->side_disty - mlx->cu->delta_y);
	return (wall);
}

/*
	moves a ray through the map tiles, akin to brensham's.
*/
void	move_ray(t_mlx *mlx)
{
	int	hit;

	hit = 0;
	update_map_pos(mlx);
	while (!hit)
	{
		if (mlx->cu->side_distx < mlx->cu->side_disty)
		{
			mlx->cu->side_distx += mlx->cu->delta_x;
			mlx->cu->mapx += mlx->cu->stepx;
			mlx->cu->side = 0;
		}
		else
		{
			mlx->cu->side_disty += mlx->cu->delta_y;
			mlx->cu->mapy += mlx->cu->stepy;
			mlx->cu->side = 1;
		}
		hit = is_wall_hit(mlx);
	}
}
