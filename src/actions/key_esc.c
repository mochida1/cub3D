/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_esc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:08:39 by hmochida          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/02/08 20:28:09 by viferrei         ###   ########.fr       */
=======
/*   Updated: 2023/02/11 15:52:46 by hmochida         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_esc(t_mlx *mlx)
{
	printf("\033[31;1mClosing Cub32...\033[0m\n");
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	printf("\033[32;1mCub3D closed successfully.\033[0m\n");
	exit (0);
}

int	red_x_close(t_mlx *mlx)
{
	printf("\033[31;1mClosing Cub32...\033[0m\n");
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	printf("\033[32;1mCub3D closed successfully.\033[0m\n");
	exit (0);
	return (0);
}
