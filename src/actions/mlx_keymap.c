/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keymap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:53:33 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/21 20:52:11 by hmochida         ###   ########.fr       */
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
		return (0);
	}
	else if (keycode == KEY_RIGHT)
	{
		printf("KEY: -> pressed\n");
		return (0);
	}
	return (1);
}

/*
** placeholder. actions for keycodes W, A, S , D
*/
int	keymap01(int keycode, t_mlx *mlx)
{
	(void) mlx;
	if (keycode == KEY_A)
	{
		printf("KEY: A pressed\n");
		return (0);
	}
	else if (keycode == KEY_S)
	{
		printf("KEY: S pressed\n");
		return (0);
	}
	else if (keycode == KEY_D)
	{
		printf("KEY: D pressed\n");
		return (0);
	}
	else if (keycode == KEY_W)
	{
		printf("KEY: W pressed\n");
		return (0);
	}
	return (1);
}
