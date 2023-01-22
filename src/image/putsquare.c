/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putsquare.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:21:43 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/22 15:45:32 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	writes a square of size N and color color into
	position X, Y of img data buffer;
*/
void	ft_mlx_putsquare_purp(int x, int y, int size, t_img *img)
{
	int	xi;
	int	yi;

	xi = 0;
	yi = 0;
	while (yi < size)
	{
		while (xi < size)
		{
			ft_mlx_putpix(x + xi, y + yi, C_PURP, img);
			xi++;
		}
		xi = 0;
		yi++;
	}
}

void	ft_mlx_putsquare_llpink(int x, int y, int size, t_img *img)
{
	int	xi;
	int	yi;

	xi = 0;
	yi = 0;
	while (yi < size)
	{
		while (xi < size)
		{
			ft_mlx_putpix(x + xi, y + yi, C_LLPINK, img);
			xi++;
		}
		xi = 0;
		yi++;
	}
}

void	ft_mlx_putsquare_red(int x, int y, int size, t_img *img)
{
	int	xi;
	int	yi;

	xi = 0;
	yi = 0;
	while (yi < size)
	{
		while (xi < size)
		{
			ft_mlx_putpix(x + xi, y + yi, C_RED, img);
			xi++;
		}
		xi = 0;
		yi++;
	}
}

void	ft_mlx_putsquare_green(int x, int y, int size, t_img *img)
{
	int	xi;
	int	yi;

	xi = 0;
	yi = 0;
	while (yi < size)
	{
		while (xi < size)
		{
			ft_mlx_putpix(x + xi, y + yi, C_GREEN, img);
			xi++;
		}
		xi = 0;
		yi++;
	}
}
