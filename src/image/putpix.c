/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:18:49 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/21 21:19:19 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	prevents ft_mlx_putpix from drawing pixels offscreen. Thus preventing wrong
	pixles overwrites and/or segfaults.
*/
static int	protec_draw_pos(int x, int y, t_img *img)
{
	if (y < 0 || x < 0)
		return (0);
	if (y > img->h || x > img->sz_line
		/ (img->bpp / 8))
		return (0);
	return (1);
}

/*
	Puts a pixel on image data buffer at X, Y;
*/
void	ft_mlx_putpix(int x, int y, int color, t_img *img)
{
	char	*dst;

	if (!(protec_draw_pos(x, y, img)))
		return ;
	dst = img->data + (y * img->sz_line + x * (img->bpp / 8));
	*(unsigned int *) dst = color;
}
