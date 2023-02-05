/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:31:36 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/05 16:32:09 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	gets the exact wall face to be drawn
	based on ray direction and wall hit side.
*/
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
