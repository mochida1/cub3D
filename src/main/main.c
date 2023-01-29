/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:02:44 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/28 21:04:13 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>
#include "test.h"

// void	img_cub(t_img *img, t_mlx *mlx)
// {

// }

void	get_starting_direction(t_mlx *mlx, char c)
{
	if (c == 'S')
	{
		mlx->cu->dirx = 0;
		mlx->cu->diry = 1;
	}
	if (c == 'N')
	{
		mlx->cu->dirx = 0;
		mlx->cu->diry = -1;
	}
	if (c == 'E')
	{
		mlx->cu->dirx = 1;
		mlx->cu->diry = 0;
	}
	if (c == 'W')
	{
		mlx->cu->dirx = -1;
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
				mlx->cu->posy = line + 0.5;
				mlx->cu->posx = col + 0.5;
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
	mlx->cu->camera = 2 * pixel_x / (double) mlx->win_width - 1;
	mlx->cu->ray_dirx = mlx->cu->dirx + mlx->cu->planex * mlx->cu->camera;
	mlx->cu->ray_diry = mlx->cu->diry + mlx->cu->planey * mlx->cu->camera;
}

void setup_ray_x_dir(t_mlx *mlx)
{
	if (mlx->cu->ray_dirx < 0)
	{
		mlx->cu->stepx = -1;
		mlx->cu->side_distx = (mlx->cu->posx - mlx->cu->mapx) * mlx->cu->delta_x;
	}
	else
	{
		mlx->cu->stepx = 1;
		mlx->cu->side_distx = (mlx->cu->posx + 1 - mlx->cu->mapx) * mlx->cu->delta_x;
	}
}

void setup_ray_y_dir(t_mlx *mlx)
{
	if (mlx->cu->ray_diry < 0)
	{
		mlx->cu->stepy = -1;
		mlx->cu->side_disty = (mlx->cu->posy - mlx->cu->mapy) * mlx->cu->delta_y;
	}
	else
	{
		mlx->cu->stepy = 1;
		mlx->cu->side_disty = (mlx->cu->posy + 1 - mlx->cu->mapy) * mlx->cu->delta_y;
	}
}

void	setup_step_direction(t_mlx *mlx)
{
	setup_ray_x_dir(mlx);
	setup_ray_y_dir(mlx);
}

/*
	checks wether a wall was hit,
	if it was, calculates the ray's distance to the plane's pixel;
*/
void	is_wall_hit(t_mlx *mlx, int *hit)
{
	if (mlx->map->raw_layout[(int) mlx->cu->mapy][(int) mlx->cu->mapx] > 0)
		hit[0] = 1;
	if (mlx->cu->side == 0)
		mlx->cu->perp_dist = (mlx->cu->side_distx - mlx->cu->delta_x);
	else
		mlx->cu->perp_dist = (mlx->cu->side_disty - mlx->cu->delta_y);
}

/*
	moves a ray through the map tiles, akin to brensham's.
*/
void move_ray(t_mlx *mlx)
{
	int	hit;

	hit = 0;
	while(!hit)
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
		is_wall_hit(mlx, &hit);
	}
}


void	get_rays_dist_side(t_mlx *mlx, int pixel_x)
{
	if (mlx->cu->ray_dirx == 0)
		mlx->cu->delta_x = mlx->map->raw_map_max_len;
	else
		mlx->cu->delta_x = fabs(1 / mlx->cu->ray_dirx);
	if (mlx->cu->ray_diry == 0)
		mlx->cu->delta_y = mlx->map->raw_layout_size;
	else
		mlx->cu->delta_y = fabs(1 / mlx->cu->ray_diry);
	setup_step_direction(mlx);
	move_ray(mlx);
}

void	calculate_line_coords(t_mlx *mlx)
{
	mlx->cu->wall_h = (int) (mlx->win_heigh / mlx->cu->perp_dist);
	mlx->cu->wall_start = (-1 * (mlx->cu->wall_h / 2)) + (mlx->win_heigh / 2);
	if (mlx->cu->wall_start < 0)
		mlx->cu->wall_start = 0;
	mlx->cu->wall_end = (mlx->cu->wall_h /2 + mlx->win_heigh / 2);
}
/*
	draws main cube's game image.
*/
void draw_cu_image(t_mlx *mlx)
{
	int	pixel_x;

	pixel_x = 0;
	while (pixel_x < mlx->win_width)
	{
		init_rays(mlx, pixel_x);
		get_rays_dist_side(mlx, pixel_x);
		calculate_line_coords(mlx);
		pixel_x++;
	}
}

int	init_cu(t_mlx *mlx)
{
	mlx->cu = ft_calloc(1, sizeof(t_cube));
	get_starting_position(mlx);
	init_camera(mlx);
	update_map_pos(mlx);
	draw_cu_image(mlx);
	printf("start position is X:[%f] Y:[%f]\n", mlx->cu->posx, mlx->cu->posy);
	printf("start direction is X:[%f] Y:[%f]\n", mlx->cu->dirx, mlx->cu->diry);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_raw_map	*map;
	t_mlx		*mlx;

	input_parsing(argc, argv);
	map = init_map("map.cub");
	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WINDOW_W, WINDOW_H, "Janella");
	mlx->map = map;
	init_cu(mlx);
	ft_mlx_init_image(mlx, map->raw_map_max_len * 2, map->raw_layout_size * 2, "minimap");
	ft_mlx_init_image(mlx, MM_SCALE, MM_SCALE, "miniplayer");
	ft_mlx_init_image(mlx, WINDOW_W, WINDOW_H, "cub");
	img_minimap(ft_mlx_get_image_by_label(mlx, "minimap"), map);
	img_miniplayer(ft_mlx_get_image_by_label(mlx, "miniplayer"), mlx->cu->posx, mlx->cu->posy);
	// img_cub(ft_mlx_get_image_by_label(mlx, "cub"), mlx);
	event_handler(mlx);

	render_images(mlx);
	mlx_loop(mlx->mlx_ptr);
	map = destroy_map(map);
	(void) argc;
	(void) argv;
}
