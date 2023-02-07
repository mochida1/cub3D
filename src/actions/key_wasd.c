/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_wasd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:53:34 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/07 19:29:43 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_w(t_mlx *mlx)
{
	int	colision;

	colision = colision_w(mlx);
	if (!(colision & COLISION_Y))
		mlx->cu->posy += mlx->cu->diry * MOVESPEED;
	if (!(colision & COLISION_X))
		mlx->cu->posx += mlx->cu->dirx * MOVESPEED;
}

void	key_a(t_mlx *mlx)
{
	double	mv_dirx;
	double	mv_diry;
	int		colision;

	mv_diry = mlx->cu->dirx * 1 + mlx->cu->diry * 0;
	mv_dirx = mlx->cu->dirx * 0 - mlx->cu->diry * 1;
	colision = colision_a(mlx, mv_diry, mv_dirx);
	if (!(colision & COLISION_Y))
		mlx->cu->posy += mv_diry * MOVESPEED;
	if (!(colision & COLISION_X))
		mlx->cu->posx += mv_dirx * MOVESPEED;
}

void	key_s(t_mlx *mlx)
{
	int	colision;

	colision = colision_s(mlx);
	if (!(colision & COLISION_Y))
		mlx->cu->posy += mlx->cu->diry * -MOVESPEED;
	if (!(colision & COLISION_X))
		mlx->cu->posx += mlx->cu->dirx * -MOVESPEED;
}

void	key_d(t_mlx *mlx)
{
	double	mv_dirx;
	double	mv_diry;
	int		colision;

	mv_diry = mlx->cu->dirx * 1 + mlx->cu->diry * 0;
	mv_dirx = mlx->cu->dirx * 0 - mlx->cu->diry * 1;
	colision = colision_d(mlx, mv_diry, mv_dirx);
	if (!(colision & COLISION_Y))
		mlx->cu->posy += mv_diry * -MOVESPEED;
	if (!(colision & COLISION_X))
		mlx->cu->posx += mv_dirx * -MOVESPEED;
}
