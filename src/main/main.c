/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:02:44 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/21 17:39:50 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>

/*
	prevents ft_mlx_putpix from drawing pixels offscreen. Thus preventing wrong
	pixles overwrites and/or segfaults.
*/
static int	protec_draw_pos(int x, int y, t_img *img)
{
	if (y < 0 || x < 0)
		return (0);
	if (y > img->h || x > img->sz_line
		/ (img->bpp / 8))
		return (0);
	return (1);
}


/*
	Puts a pixel on image data buffer at X, Y;
*/
void	ft_mlx_putpix(int x, int y, int color, t_img *img)
{
	char	*dst;

	if (!(protec_draw_pos(x, y, img)))
		return ;
	dst = img->data + (y * img->sz_line + x * (img->bpp / 8));
	*(unsigned int *) dst = color;
}

/*
	writes a square of size N and color color into position X, Y of img data buffer;
*/
void	ft_mlx_putsquare_purp(int x, int y, int size, t_img *img)
{
	int	xi;
	int yi;

	xi = 0;
	yi = 0;
	while (yi < size)
	{
		while (xi < size)
		{
			ft_mlx_putpix(x + xi, y + yi, C_PURP, img);
			xi++;
		}
		xi = 0;
		yi++;
	}
}

void	ft_mlx_putsquare_llpink(int x, int y, int size, t_img *img)
{
	int	xi;
	int yi;

	xi = 0;
	yi = 0;
	while (yi < size)
	{
		while (xi < size)
		{
			ft_mlx_putpix(x + xi, y + yi, C_LLPINK, img);
			xi++;
		}
		xi = 0;
		yi++;
	}
}
void	ft_mlx_putsquare_green(int x, int y, int size, t_img *img)
{
	int	xi;
	int yi;

	xi = 0;
	yi = 0;
	while (yi < size)
	{
		while (xi < size)
		{
			ft_mlx_putpix(x + xi, y + yi, C_GREEN, img);
			xi++;
		}
		xi = 0;
		yi++;
	}
}


void	render_write_minimap(t_img *img, t_raw_map * map, int scaling_factor)
{
	int	line;
	int	row;

	line = 0;
	row = 0;
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->sz_line, &img->endian);
	// memset((char *)img->data, 0xff, img->w * img->h * img->bpp/8);
	while (map->raw_layout[line])
	{
		if (!map->raw_layout[line][row])
		{
			line ++;
			row = 0;
			continue ;
		}
		else if (map->raw_layout[line][row] == '1')
			ft_mlx_putsquare_purp(row * scaling_factor, line * scaling_factor, scaling_factor, img);
		else if (map->raw_layout[line][row] == '0')
			ft_mlx_putsquare_llpink(row * scaling_factor, line * scaling_factor, scaling_factor, img);
		else if (ft_strchr("NWES", map->raw_layout[line][row]))
			ft_mlx_putsquare_green(row * scaling_factor, line * scaling_factor, scaling_factor, img);
		row ++;
	}
}

void	render_minimap(t_mlx *mlx, t_img *img, t_raw_map *map)
{
	render_write_minimap(img, map, 2);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, 50, 50);
	(void) map;
}

t_img	*ft_mlx_init_image(t_mlx *mlx, unsigned int x, unsigned int y)
{
	t_img *img;

	img = ft_calloc(1, sizeof(t_img));
	img->h = x;
	img->w = y;
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, img->h, img->w);
	return (img);
}

int	main(int argc, char *argv[])
{
	t_raw_map	*map;
	t_mlx		*mlx;
	t_img		*minimap;

	map = init_map("map.cub");
	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 800, 600, "Janella");

	minimap = ft_mlx_init_image(mlx, map->raw_map_max_len * 2, map->raw_layout_size *2);
	event_handler(mlx);

	render_minimap(mlx, minimap, map);

	mlx_loop(mlx->mlx_ptr);
	mlx_destroy_image(mlx->mlx_ptr, minimap->img_ptr);
	free(minimap);
	map = destroy_map(map);
	(void) argc;
	(void) argv;
}
