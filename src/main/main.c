/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:02:44 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/18 22:01:23 by hmochida         ###   ########.fr       */
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
	dst = img->data + (y * img->sz_line + x
			* (img->bpp / 8));
	*(unsigned int *) dst = color;
}

void	render_minimap(t_mlx *mlx, t_img *img, t_raw_map *map)
{

	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->sz_line, &img->endian);
	img->w = 400;
	img->h = 300;
	memset((int*)img->data, 0xffddff, img->w * img ->h);

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, 10, 10);
	(void) map;
}

int	main(int argc, char *argv[])
{
	t_raw_map	*map;
	t_mlx		*mlx;
	t_img		img;

	map = init_map("map.cub");
	mlx = ft_calloc(1, sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 800, 600, "Janella");
	img.img_ptr = mlx_new_image(mlx->mlx_ptr, /*map->raw_map_max_len*/400, /*map->raw_layout_size*/300);
	event_handler(mlx);

	render_minimap(mlx, &img, map);

	mlx_loop(mlx->mlx_ptr);
	mlx_destroy_image(mlx->mlx_ptr, img.img_ptr);
	map = destroy_map(map);
	(void) argc;
	(void) argv;
}
