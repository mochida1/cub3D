/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:23:05 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/14 20:29:48 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	event_handler(void *win_ptr)
{
	// mlx_hook(win_ptr, X_KEYPRESS, 1L << 0, key_press, img);
	mlx_hook(win_ptr, RED_X, 1L << 17, red_x_close, img);
	// mlx_expose_hook(win_ptr, &render, img);
}

int	key_press(int keycode, void *data)
{
	int	i;

	i = 0;
	i = keymap00(keycode, img);
	if (i)
		i = keymap01(keycode, img);
	if (i)
		i = keymap02(keycode, img);
	return (0);
}
