/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_wasd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:53:34 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/05 10:59:52 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_w(t_mlx *mlx)
{
	// if()
		mlx->cu->posy += mlx->cu->diry * MOVESPEED;
	// if()
		mlx->cu->posx += mlx->cu->dirx * MOVESPEED;
}

void	key_a(t_mlx *mlx)
{
	double	mv_dirx;
	double	mv_diry;

	mv_diry = mlx->cu->dirx * 1 + mlx->cu->diry * 0;
	mv_dirx = mlx->cu->dirx * 0 - mlx->cu->diry * 1;
	// if(mlx->map->raw_layout[(int)(mlx->cu->posy + mv_diry * MOVESPEED)][(int)mlx->cu->posx])
		mlx->cu->posy += mv_diry * MOVESPEED;
	// if(mlx->map->raw_layout[(int)mlx->cu->posy][(int)(mlx->cu->posx + mv_dirx * MOVESPEED)])
		mlx->cu->posx += mv_dirx * MOVESPEED;
}

void	key_s(t_mlx *mlx)
{
	// if()
		mlx->cu->posy += mlx->cu->diry * -MOVESPEED;
	// if()
		mlx->cu->posx += mlx->cu->dirx * -MOVESPEED;
}

void	key_d(t_mlx *mlx)
{
	double	mv_dirx;
	double	mv_diry;

	mv_diry = mlx->cu->dirx * 1 + mlx->cu->diry * 0;
	mv_dirx = mlx->cu->dirx * 0 - mlx->cu->diry * 1;
	// if()
		mlx->cu->posy += mv_diry * -MOVESPEED;
	// if()
		mlx->cu->posx += mv_dirx * -MOVESPEED;
}
