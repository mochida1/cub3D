/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:23:11 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/04 16:43:31 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_images(t_mlx *mlx)
{
	t_img	*temp;

	temp = mlx->img_list_head;
	if (!temp)
	{
		write(2, "ERROR: render failed to get image list\n", 40);
		exit (1);
	}
	while (temp)
	{
		if (!temp->hide)
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				temp->img_ptr, temp->win_x, temp->win_y);
		temp = temp->next;
	}
	printf("posx: [%f]\n",mlx->cu->posx);
	printf("posy: [%f]\n",mlx->cu->posy);
	printf("dirx: [%f]\n",mlx->cu->dirx);
	printf("diry: [%f]\n",mlx->cu->diry);
	return (0);
}
