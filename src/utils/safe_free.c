/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 00:44:38 by coder             #+#    #+#             */
/*   Updated: 2023/02/12 17:35:15 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_and_exit(t_mlx *mlx, int exit_code)
{
	t_img	*temp;

	if (mlx)
	{
		while (mlx->img_list_head)
		{
			temp = mlx->img_list_head;
			safe_free(mlx->img_list_head->img_ptr);
			safe_free(mlx->img_list_head->label);
			safe_free(mlx->img_list_head->data);
			mlx->img_list_head = mlx->img_list_head->next;
			safe_free(temp);
		}
		if (mlx->cu)
			free(mlx->cu);
		if (mlx->map)
			destroy_map(mlx->map);
		if (mlx->settings)
			free_settings(mlx->settings);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		safe_free(mlx->mlx_ptr);
		free(mlx);
	}
	exit(exit_code);
}

void	*free_settings(t_settings *settings)
{
	safe_free(settings->north_texture);
	safe_free(settings->south_texture);
	safe_free(settings->west_texture);
	safe_free(settings->east_texture);
	safe_free(settings);
	return (NULL);
}

void	*safe_free(void *content)
{
	if (content != NULL)
	{
		free(content);
		content = NULL;
		return (NULL);
	}
	return (NULL);
}

void	*free_string_array(char	**pp)
{
	int	i;

	i = 0;
	if (!pp)
		return (NULL);
	while (pp[i])
	{
		pp[i] = safe_free(pp[i]);
		i++;
	}
	pp = safe_free(pp);
	return (NULL);
}
