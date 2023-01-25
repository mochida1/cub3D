/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:57:32 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/24 21:53:40 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>		// open
# include <unistd.h>		// close, read, write
# include <stdio.h>		// printf
# include <stdlib.h>		// malloc, free, exit
# include <errno.h>		// perror
# include <string.h>		// strerror
# include <mlx.h>		//mlx sutff

# include "../libft/libft.h"
# include "cub_utils.h"
# include "cub_defs.h"
# include "cub_mlx_keymap.h"

/* MAP UTILS */
t_raw_map	*init_map(char *path_to_map);
void		*destroy_map(t_raw_map *map);
void		map_disassemble(t_raw_map *map);
void		get_map_raw_layout(t_raw_map *map);

/* ACTIONS */
void		event_handler(t_mlx *mlx);
int			red_x_close(t_mlx *mlx);
void		key_esc(t_mlx *mlx);

/* RENDER */
int			render_images(t_mlx *mlx);

/* IMAGE DRAWING */
void	ft_mlx_putpix(int x, int y, int color, t_img *img);
void	ft_mlx_putsquare_purp(int x, int y, int size, t_img *img);
void	ft_mlx_putsquare_llpink(int x, int y, int size, t_img *img);
void	ft_mlx_putsquare_red(int x, int y, int size, t_img *img);
void	ft_mlx_putsquare_green(int x, int y, int size, t_img *img);
void	img_minimap(t_img *img, t_raw_map * map);
void	img_miniplayer(t_img *img, int miniplayer_x, int miniplayer_y);

/* IMAGE LINKED LIST */
t_img	*ft_mlx_init_image(t_mlx *mlx, unsigned int x, unsigned int y, char *label);
int		ft_mlx_add_to_img_list(t_mlx *mlx, t_img *img);
int		ft_mlx_img_list_total_index(t_mlx *mlx);
void	*ft_mlx_get_image_by_label(t_mlx *mlx, char *label);

// get_map_settings.c
int			get_raw_map_settings(t_raw_map *map);
int			get_settings(t_settings *settings, char **raw_cfg);

/* UTILS */
char		**ft_split_spaces(char const *s);
int			ft_strcmp(char *str, char *str2);

#endif //CUB3D_H
