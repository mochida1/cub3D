/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:18:59 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/11 20:26:24 by hmochida         ###   ########.fr       */
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
	sets initial position and step size for iteration on the
	column of a texture;
*/
void set_tx_y(t_mlx *mlx)
{
	mlx->tx[mlx->cu->wall_face].step_size = 1.0 * mlx->tx[mlx->cu->wall_face].h / mlx->cu->wall_h;
	// printf("step: %f\n", mlx->tx[mlx->cu->wall_face].step_size);
	mlx->tx[mlx->cu->wall_face].position = (mlx->cu->wall_start - mlx->tx[mlx->cu->wall_face].h / 2 + mlx->cu->wall_h / 2) * mlx->tx[mlx->cu->wall_face].step_size;
	printf("position: %f\n", mlx->tx[mlx->cu->wall_face].position);
}

int	get_color_from_data(char *ptr)
{
	char	rgba[4];

	rgba[3] = 0x00;
	rgba[2] = ptr[2];
	rgba[1] = ptr[1];
	rgba[0] = ptr[0];
	int *ret = (int*) rgba;
	return(*ret);
}

/*
	IMPLEMENTAR!!!
*/
static int	get_color_from_texture(t_mlx *mlx)
{
	char	*ptr;
	int		color;
	int		tx_y;

	tx_y = (int)mlx->tx[mlx->cu->wall_face].position & (mlx->tx[mlx->cu->wall_face].h - 1);
	ptr = mlx->tx[mlx->cu->wall_face].data + (tx_y * mlx->tx[mlx->cu->wall_face].sz_line + mlx->cu->tx_x * (mlx->tx[mlx->cu->wall_face].bpp / 8));
	color = get_color_from_data(ptr);
	return (color);
}

/*
	returns the texture column to start drawing the wall.
*/
double get_wall_x(t_mlx *mlx)
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
int get_tx_x(t_mlx *mlx)
{
	int ret;
	double wall_hit_x;

	wall_hit_x = get_wall_x(mlx);
	ret = (int) (wall_hit_x * (double) mlx->tx[mlx->cu->wall_face].w);
	if(mlx->cu->side == 0 && mlx->cu->ray_dirx > 0)
		ret = mlx->tx[mlx->cu->wall_face].w - ret - 1;
	if(mlx->cu->side == 1 && mlx->cu->ray_diry < 0)
		ret = mlx->tx[mlx->cu->wall_face].w - ret - 1;
	return (ret);
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
		mlx->tx[mlx->cu->wall_face].position += mlx->tx[mlx->cu->wall_face].step_size;
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
