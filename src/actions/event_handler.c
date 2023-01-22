/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:23:05 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/17 20:51:23 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_mlx *mlx)
{
	int	i;

	i = 0;
	i = keymap00(keycode, mlx);
	if (i)
		i = keymap01(keycode, mlx);
	return (0);
}

void	event_handler(t_mlx *mlx)
{
	printf("Registering MLX hooks\n");
	mlx_key_hook(mlx->win_ptr, key_press, mlx);
	mlx_hook(mlx->win_ptr, RED_X, 1L << 17, red_x_close, mlx);
	//  mlx_expose_hook(win_ptr, &render, img);
}
