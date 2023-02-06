/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_lr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:01:27 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/05 11:14:19 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_left(t_mlx *mlx)
{
	double	old_dirx;
	double	old_planex;

	old_planex = mlx->cu->planex;
	old_dirx = mlx->cu->dirx;
	mlx->cu->dirx = mlx->cu->dirx * COS5DEG - mlx->cu->diry * SIN5DEG;
	mlx->cu->diry = old_dirx * SIN5DEG + mlx->cu->diry * COS5DEG;
	mlx->cu->planex = mlx->cu->planex * COS5DEG - mlx->cu->planey * SIN5DEG;
	mlx->cu->planey = old_planex * SIN5DEG + mlx->cu->planey * COS5DEG;
}

void	key_right(t_mlx *mlx)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = mlx->cu->dirx;
	old_planex = mlx->cu->planex;
	mlx->cu->dirx = mlx->cu->dirx * COS5DEG - mlx->cu->diry * -SIN5DEG;
	mlx->cu->diry = old_dirx * -SIN5DEG + mlx->cu->diry * COS5DEG;
	mlx->cu->planex = mlx->cu->planex * COS5DEG - mlx->cu->planey * -SIN5DEG;
	mlx->cu->planey = old_planex * -SIN5DEG + mlx->cu->planey * COS5DEG;
}
