/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:28:32 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/29 17:13:16 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	initializes some shit in img_minimap().
*/
void	ugly_norminette_workaround(int *line, int *row, t_img *img)
{
	*line = 0;
	*row = 0;
	img->win_x = MINIMAP_X;
	img->win_y = MINIMAP_Y;
}

void	img_minimap(t_img *img, t_raw_map *map)
{
	int	line;
	int	row;

	ugly_norminette_workaround(&line, &row, img);
	while (map->raw_layout[line])
	{
		if (!map->raw_layout[line][row])
		{
			line ++;
			row = 0;
			continue ;
		}
		else if (map->raw_layout[line][row] == '1')
			ft_mlx_putsquare_purp(row * MM_SCALE,
				line * MM_SCALE, MM_SCALE, img);
		else if (map->raw_layout[line][row] == '0')
			ft_mlx_putsquare_llpink(row * MM_SCALE,
				line * MM_SCALE, MM_SCALE, img);
		else if (ft_strchr("NWES", map->raw_layout[line][row]))
			ft_mlx_putsquare_green(row * MM_SCALE,
				line * MM_SCALE, MM_SCALE, img);
		row ++;
	}
}

void	img_miniplayer(t_img *img, int miniplayer_x, int miniplayer_y)
{
	img->win_x = (miniplayer_x * MM_SCALE) + MINIMAP_X;
	img->win_y = (miniplayer_y * MM_SCALE) + MINIMAP_Y;
	printf("miniplayer x: %d\n",img->win_x);
	printf("miniplayer y: %d\n",img->win_y);
	memset((char *)img->data, C_TEST, img->w * img->h * img->bpp / 8);
}
