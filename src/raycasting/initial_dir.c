/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:47:55 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/05 13:22:48 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pos_is_w(t_mlx *mlx)
{
	mlx->cu->dirx = -1;
	mlx->cu->diry = 0;
}

void	pos_is_s(t_mlx	*mlx)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = mlx->cu->dirx;
	old_planex = mlx->cu->planex;
	mlx->cu->dirx = mlx->cu->dirx * COS90DEG - mlx->cu->diry * -SIN90DEG;
	mlx->cu->diry = old_dirx * -SIN90DEG + mlx->cu->diry * COS90DEG;
	mlx->cu->planex = mlx->cu->planex * COS90DEG - mlx->cu->planey * -SIN90DEG;
	mlx->cu->planey = old_planex * -SIN90DEG + mlx->cu->planey * COS90DEG;
}

void	pos_is_n(t_mlx *mlx)
{
	double	old_dirx;
	double	old_planex;

	old_planex = mlx->cu->planex;
	old_dirx = mlx->cu->dirx;
	mlx->cu->dirx = mlx->cu->dirx * COS90DEG - mlx->cu->diry * SIN90DEG;
	mlx->cu->diry = old_dirx * SIN90DEG + mlx->cu->diry * COS90DEG;
	mlx->cu->planex = mlx->cu->planex * COS90DEG - mlx->cu->planey * SIN90DEG;
	mlx->cu->planey = old_planex * SIN90DEG + mlx->cu->planey * COS90DEG;
}

void	pos_is_e(t_mlx *mlx)
{
	double	old_dirx;
	double	old_planex;

	old_planex = mlx->cu->planex;
	old_dirx = mlx->cu->dirx;
	mlx->cu->dirx = mlx->cu->dirx * COS180DEG - mlx->cu->diry * SIN180DEG;
	mlx->cu->diry = old_dirx * SIN180DEG + mlx->cu->diry * COS180DEG;
	mlx->cu->planex = mlx->cu->planex * COS180DEG - mlx->cu->planey * SIN180DEG;
	mlx->cu->planey = old_planex * SIN180DEG + mlx->cu->planey * COS180DEG;
}

void	rotate_to_starting_dir(t_mlx *mlx)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (mlx->map->raw_layout[line])
	{
		while (mlx->map->raw_layout[line][col])
		{
			if (!int_strrchr("NSWE", mlx->map->raw_layout[line][col]))
			{
				get_starting_direction(mlx, mlx->map->raw_layout[line][col]);
				return ;
			}
			col++;
		}
		col = 0;
		line++;
	}
}
