/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_lr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:01:27 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/05 11:07:23 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_left(t_mlx *mlx)
{
	double	old_dirx;
	double	old_planex;

	old_planex = mlx->cu->planex;
	old_dirx = mlx->cu->dirx;
	mlx->cu->dirx = mlx->cu->dirx * 0.99619469809 - mlx->cu->diry * 0.08715574274;
	mlx->cu->diry = old_dirx * 0.08715574274 + mlx->cu->diry * 0.99619469809;
	mlx->cu->planex = mlx->cu->planex * 0.99619469809 - mlx->cu->planey * 0.08715574274;
	mlx->cu->planey = old_planex * 0.08715574274 + mlx->cu->planey * 0.99619469809;
}

void	key_right(t_mlx *mlx)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = mlx->cu->dirx;
	old_planex = mlx->cu->planex;
	mlx->cu->dirx = mlx->cu->dirx * 0.99619469809 - mlx->cu->diry * -0.08715574274;
	mlx->cu->diry = old_dirx * -0.08715574274 + mlx->cu->diry * 0.99619469809;
	mlx->cu->planex = mlx->cu->planex * 0.99619469809 - mlx->cu->planey * -0.08715574274;
	mlx->cu->planey = old_planex * -0.08715574274 + mlx->cu->planey * 0.99619469809;
}
