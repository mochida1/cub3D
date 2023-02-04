/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:02:44 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/04 16:25:52 by hmochida         ###   ########.fr       */
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
		mlx->cu->dirx = 1;
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
				mlx->cu->posx = col + 0.5; // coordenadas estranhas
				mlx->cu->posy = line + 0.5; // coordenadas estranhas
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
	static t_img	*cube_img;

	if (!cube_img)
		cube_img = ft_mlx_get_image_by_label(mlx, "cube");
	mlx->cu->camera = 2 * pixel_x / (double) cube_img->w - 1;
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
int	is_wall_hit(t_mlx *mlx)
{
	int wall;

	wall = 0;
	if (mlx->cu->mapx < 0)
	{
		printf("mapX < 0: something went bad!\n");
		exit (1);
	}
	if (mlx->cu->mapy < 0)
	{
		printf("mapy < 0: something went bad!\n");
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
void move_ray(t_mlx *mlx)
{
	int	hit;

	hit = 0;
	update_map_pos(mlx);
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
		hit = is_wall_hit(mlx);
	}
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

int	draw_ceiling(t_mlx *mlx, t_img *cube_img, int pixel_x, int count)
{
	while(count < mlx->cu->wall_start)
	{
		ft_mlx_putpix(pixel_x, count, mlx->cu->color, cube_img);
		count++;
	}
	return (count);
}

/*
	IMPLEMENTAR!!!
*/
int	get_color_from_texture(t_mlx *mlx)
{
	if (mlx->cu->side == 1)
		return (0xaa0000);
	else
		return (0x00ff00);

}

/*
	effectivelly draws the walls on the data array of the image;
*/
int	draw_wall(t_mlx *mlx, t_img *cube_img, int pixel_x, int count)
{
	while(count < mlx->cu->wall_end)
	{
		mlx->cu->color = get_color_from_texture(mlx);
		ft_mlx_putpix(pixel_x, count, mlx->cu->color, cube_img);
		count++;
	}
	return (count);
}

/*
	continues to draw the floor after drawing the walls;
*/
int	draw_floor(t_mlx *mlx, t_img *cube_img, int pixel_x, int count)
{
	while(count < cube_img->h - 1)
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

/*
	draws main cube's game image.
*/
void draw_cu_image(t_mlx *mlx)
{
	int				pixel_x;
	static t_img	*cube_img;

	printf("cube_img_ptr: %p\n", cube_img);
	if (!cube_img)
		cube_img = ft_mlx_get_image_by_label(mlx, "cube");
	pixel_x = 0;
	while (pixel_x < cube_img->w)
	{
		init_rays(mlx, pixel_x);
		get_rays_dist_side(mlx);
		calculate_line_coords(mlx);
		draw_column(mlx, cube_img, pixel_x);
		pixel_x++;
	}

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

void	img_cub(t_mlx *mlx)
{
	update_map_pos(mlx);
	printf("POSX: %f\tPOSY: %f\n",mlx->cu->posx, mlx->cu->posy);
	draw_cu_image(mlx);
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
	ft_mlx_init_image(mlx, WINDOW_W, WINDOW_H, "cube");
	ft_mlx_init_image(mlx, map->raw_layout_size * 2, (map->raw_map_max_len - 1) * 2, "minimap");
	ft_mlx_init_image(mlx, MM_SCALE, MM_SCALE, "miniplayer");
	init_cu(mlx);
	img_minimap(ft_mlx_get_image_by_label(mlx, "minimap"), map);
	img_miniplayer(ft_mlx_get_image_by_label(mlx, "miniplayer"), mlx->cu->posx, mlx->cu->posy);
	img_cub(mlx);
	event_handler(mlx);

	render_images(mlx);
	mlx_loop(mlx->mlx_ptr);
	map = destroy_map(map);
}
