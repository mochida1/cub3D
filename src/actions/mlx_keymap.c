/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keymap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:53:33 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/14 22:16:47 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** actions for keycodes ESC, Q, W, E
*/
int	keymap00(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		key_esc(mlx);
	else if (keycode == KEY_E)
	{
		return (0);
	}
	return (1);
}

/*
** placeholder. actions for keycodes A, S , D
*/
int	keymap01(int keycode, t_mlx *mlx)
{
	(void) mlx;
	if (keycode == KEY_A)
	{
		return (0);
	}
	else if (keycode == KEY_S)
	{
		return (0);
	}
	else if (keycode == KEY_D)
	{
		return (0);
	}
		else if (keycode == KEY_W)
	{
		return (0);
	}
	return (1);
}

/*
** placeholder. actions for keycodes R, F, Z, C
*/
int	keymap02(int keycode, t_mlx *mlx)
{
	(void) mlx;
	if (keycode == KEY_R)
	{
		return (0);
	}
	else if (keycode == KEY_F)
	{
		return (0);
	}
	else if (keycode == KEY_Z)
	{
		return (0);
	}
	else if (keycode == KEY_C)
	{
		return (0);
	}
	return (1);
}

/*
** placeholder. actions for keycodes I, O, P, SPACE.
*/
int	keymap03(int keycode, t_mlx *mlx)
{
	(void) mlx;
	if (keycode == KEY_I)
	{
		return (0);
	}
	else if (keycode == KEY_O)
	{
		return (0);
	}
	else if (keycode == KEY_P)
	{
		return (0);
	}
	else if (keycode == KEY_SPACE)
	{
		return (0);
	}
	return (1);
}
