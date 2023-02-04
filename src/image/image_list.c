/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:31:26 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/04 19:17:12 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	returns a handle of the image
*/
void	*ft_mlx_get_image_by_label(t_mlx *mlx, char *label)
{
	t_img	*temp;

	temp = mlx->img_list_head;
	while (temp)
	{
		if (!ft_strcmp(temp->label, label))
			return (temp);
		temp = temp->next;
	}
	return (0);
}

/*
	lists the total number of elements inside the image list
*/
int	ft_mlx_img_list_total_index(t_mlx *mlx)
{
	t_img	*temp;
	int		ret;

	temp = mlx->img_list_head;
	ret = -1;
	while (temp && temp->next)
	{
		temp = temp->next;
		ret++;
	}
	return (ret);
}

/*
	adds a pointer of given image to the end of the list;
*/
int	ft_mlx_add_to_img_list(t_mlx *mlx, t_img *img)
{
	int		index;
	t_img	*temp;

	index = 0;
	temp = mlx->img_list_head;
	img->next = NULL;
	if (!mlx->img_list_head)
	{
		mlx->img_list_head = img;
		return (index);
	}
	while (temp)
	{
		index++;
		if (!temp->next)
		{
			temp->next = img;
			return (index);
		}
		temp = temp->next;
	}
	return (index);
}

/*
	inits an image to be rendered at screen's x y. A label must be added.
*/
t_img	*ft_mlx_init_image(t_mlx *mlx, unsigned int x,
	unsigned int y, char *label)
{
	t_img	*img;

	if (!label)
	{
		write(2, "CRITICAL ERROR: Tried to create unlabeled image\n", 48);
		exit (1);
	}
	img = ft_calloc(1, sizeof(t_img));
	img->h = y;
	img->w = x;
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, img->w, img->h);
	img->label = label;
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->sz_line,
			&img->endian);
	ft_mlx_add_to_img_list(mlx, img);
	img->index = ft_mlx_img_list_total_index(mlx);
	return (img);
}
