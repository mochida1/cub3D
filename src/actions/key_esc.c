/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_esc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:08:39 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/14 22:16:45 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_esc(t_mlx *mlx)
{
	printf("\033[31;1mClosing Cub32...\033[0m\n");

	// mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);

	printf("\033[32;1mCub3D closed successfully.\033[0m\n");
	exit (0);
}

int	red_x_close(t_mlx *mlx)
{
	printf("\033[31;1mClosing Cub32...\033[0m\n");

	// mlx_destroy_image(img->mlx_ptr, img->img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);

	printf("\033[32;1mCub3D closed successfully.\033[0m\n");
	exit (0);
	return (0);
}
