/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keymap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:53:33 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/05 11:07:55 by hmochida         ###   ########.fr       */
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
		key_left(mlx);
		return (0);
	}
	else if (keycode == KEY_RIGHT)
	{
		key_right(mlx);
		return (0);
	}
	return (1);
}

/*
** actions for keycodes W, A, S , D
*/
int	keymap01(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_A)
	{
		key_a(mlx);
		return (0);
	}
	else if (keycode == KEY_S)
	{
		key_s(mlx);
		return (0);
	}
	else if (keycode == KEY_D)
	{
		key_d(mlx);
		return (0);
	}
	else if (keycode == KEY_W)
	{
		key_w(mlx);
		return (0);
	}
	return (1);
}
