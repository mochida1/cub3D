/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keymap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:53:33 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/04 16:45:55 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "test.h"

/*
** actions for keycodes ESC, Left and Right arrows.
*/
int	keymap00(int keycode, t_mlx *mlx)
{

	if (keycode == KEY_ESC)
		key_esc(mlx);
	else if (keycode == KEY_LEFT)
	{
		printf("KEY: <- pressed\n");
		double oldDirX = mlx->cu->dirx;
		double oldPlaneX = mlx->cu->planex;
		mlx->cu->dirx = mlx->cu->dirx * 0.99619469809 - mlx->cu->diry * 0.08715574274;
		mlx->cu->diry = oldDirX * 0.08715574274 + mlx->cu->diry * 0.99619469809;
		mlx->cu->planex = mlx->cu->planex * 0.99619469809 - mlx->cu->planey * 0.08715574274;
		mlx->cu->planey = oldPlaneX * 0.08715574274 + mlx->cu->planey * 0.99619469809;
		img_cub(mlx);
		render_images(mlx);
		return (0);
	}
	else if (keycode == KEY_RIGHT)
	{
		printf("KEY: -> pressed\n");
		double oldDirX = mlx->cu->dirx;
		double oldPlaneX = mlx->cu->planex;
		mlx->cu->dirx = mlx->cu->dirx * 0.99619469809 - mlx->cu->diry * -0.08715574274;
		mlx->cu->diry = oldDirX * -0.08715574274 + mlx->cu->diry * 0.99619469809;
		mlx->cu->planex = mlx->cu->planex * 0.99619469809 - mlx->cu->planey * -0.08715574274;
		mlx->cu->planey = oldPlaneX * -0.08715574274 + mlx->cu->planey * 0.99619469809;
		img_cub(mlx);
		render_images(mlx);
		return (0);
	}
	return (1);
}

/*
** placeholder. actions for keycodes W, A, S , D
*/
int	keymap01(int keycode, t_mlx *mlx)
{
	double	mv_dirx;
	double	mv_diry;
	if (keycode == KEY_A)
	{
		printf("KEY: A pressed\n");
		mv_diry = mlx->cu->dirx * 0 - mlx->cu->diry * 1;
		mv_dirx = mlx->cu->dirx * 1 + mlx->cu->diry * 0;

		// if(mlx->map->raw_layout[(int)(mlx->cu->posy + mv_diry * (MOVESPEED * 1.1 ))][(int)mlx->cu->posx] == '1')
			mlx->cu->posy += mv_diry * MOVESPEED;
		// if(mlx->map->raw_layout[(int)mlx->cu->posy][(int)(mlx->cu->posx + mv_dirx * (MOVESPEED * 1.1 ))] == '1')
			mlx->cu->posx += mv_dirx * MOVESPEED;
		img_cub(mlx);
		render_images(mlx);
		return (0);
	}
	else if (keycode == KEY_S)
	{
		printf("KEY: S pressed\n");
		// if(mlx->map->raw_layout[(int)(mlx->cu->posy + mlx->cu->diry * -1 * (MOVESPEED * 1.1 ))][(int)mlx->cu->dirx] == '1')
			mlx->cu->posy += mlx->cu->diry * -MOVESPEED;
		// if(mlx->map->raw_layout[(int)mlx->cu->posy][(int)(mlx->cu->posx + mlx->cu->diry * -1 * (MOVESPEED * 1.1 ))] == '1')
			mlx->cu->posx += mlx->cu->dirx * -MOVESPEED;
		img_cub(mlx);
		render_images(mlx);
		return (0);
	}
	else if (keycode == KEY_D)
	{
		printf("KEY: D pressed\n");
		mv_diry = mlx->cu->dirx * 0 - mlx->cu->diry * 1;
		mv_dirx = mlx->cu->dirx * 1 + mlx->cu->diry * 0;
		// if(mlx->map->raw_layout[(int)(mlx->cu->posy + mv_diry * -1 * (MOVESPEED * 1.1 ))][(int)mlx->cu->posx] == '1')
			mlx->cu->posy += mv_diry * -MOVESPEED;
		// if(mlx->map->raw_layout[(int)mlx->cu->posy][(int)(mlx->cu->posx + mv_dirx * -1 * (MOVESPEED * 1.1 ))] == '1')
			mlx->cu->posx += mv_dirx * -MOVESPEED;
		img_cub(mlx);
		render_images(mlx);
		return (0);
	}
	else if (keycode == KEY_W)
	{
		printf("KEY: W pressed\n");
		// if(mlx->map->raw_layout[(int)(mlx->cu->posy + mlx->cu->diry * (MOVESPEED * 1.1 ))][(int)mlx->cu->dirx] == '1')
			mlx->cu->posy += mlx->cu->diry * MOVESPEED;
		// if(mlx->map->raw_layout[(int)mlx->cu->posy][(int)(mlx->cu->dirx + mlx->cu->diry * (MOVESPEED * 1.1 ))] == '1')
			mlx->cu->dirx += mlx->cu->dirx * MOVESPEED;
		img_cub(mlx);
		render_images(mlx);
		return (0);
	}
	return (1);
}
