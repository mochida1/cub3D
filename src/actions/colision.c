/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:37:58 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/16 21:39:51 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Checks for collisions.
	Returns 0 if no collision would happen, 1 if a collision would happen;
*/
int	colision_a(t_mlx *mlx, double mv_diry, double mv_dirx)
{
	int	ret;

	ret = COLISION_NONE;
	if (int_strrchr("0NSWE", mlx->map->raw_layout[(int)(mlx->cu->posy
				+ mv_diry * MOVESPEED * 1.1)][(int)mlx->cu->posx]))
		ret |= COLISION_Y;
	if (int_strrchr("0NSWE", mlx->map->raw_layout[(int)mlx->cu->posy]
			[(int)(mlx->cu->posx + mv_dirx * MOVESPEED * 1.1)]))
		ret |= COLISION_X;
	return (ret);
}

int	colision_s(t_mlx *mlx)
{
	int	ret;

	ret = COLISION_NONE;
	if (int_strrchr("0NSWE", mlx->map->raw_layout[(int)(mlx->cu->posy
				+ mlx->cu->diry * -1 * MOVESPEED)][(int)mlx->cu->posx]))
		ret |= COLISION_Y;
	if (int_strrchr("0NSWE", mlx->map->raw_layout[(int)mlx->cu->posy]
			[(int)(mlx->cu->posx + mlx->cu->dirx * -1 * MOVESPEED)]))
		ret |= COLISION_X;
	return (ret);
}

int	colision_d(t_mlx *mlx, double mv_diry, double mv_dirx)
{
	int	ret;

	ret = COLISION_NONE;
	if (int_strrchr("0NSWE", mlx->map->raw_layout[(int)(mlx->cu->posy
				+ mv_diry * -1 * MOVESPEED * 1.1)][(int)mlx->cu->posx]))
		ret |= COLISION_Y;
	if (int_strrchr("0NSWE", mlx->map->raw_layout[(int)mlx->cu->posy]
			[(int)(mlx->cu->posx + mv_dirx * -1 * MOVESPEED * 1.1)]))
		ret |= COLISION_X;
	return (ret);
}

int	colision_w(t_mlx *mlx)
{
	int	ret;

	ret = COLISION_NONE;
	if (int_strrchr("0NSWE", mlx->map->raw_layout[(int)(mlx->cu->posy
				+ mlx->cu->diry * MOVESPEED)][(int)mlx->cu->posx]))
		ret |= COLISION_Y;
	if (int_strrchr("0NSWE", mlx->map->raw_layout[(int)mlx->cu->posy]
			[(int)(mlx->cu->posx + mlx->cu->dirx * MOVESPEED)]))
		ret |= COLISION_X;
	return (ret);
}
