/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:57:32 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/28 16:59:13 by hmochida         ###   ########.fr       */
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
int			validate_map(t_raw_map *map);
// map_checks.c
int			check_character(char **raw_map);
int			check_duplicate(char **raw_map);
int			check_adjacency(char **raw_map);
// map_checks_line.c
int			check_first_line(char **map);
int			check_last_line(char **map);

/* ACTIONS */
void		event_handler(t_mlx *mlx);
int			red_x_close(t_mlx *mlx);
void		key_esc(t_mlx *mlx);

/* RENDER */
int			render_images(t_mlx *mlx);

/* IMAGE DRAWING */
void		ft_mlx_putpix(int x, int y, int color, t_img *img);
void		ft_mlx_putsquare_purp(int x, int y, int size, t_img *img);
void		ft_mlx_putsquare_llpink(int x, int y, int size, t_img *img);
void		ft_mlx_putsquare_red(int x, int y, int size, t_img *img);
void		ft_mlx_putsquare_green(int x, int y, int size, t_img *img);
void		img_minimap(t_img *img, t_raw_map *map);
void		img_miniplayer(t_img *img, int miniplayer_x, int miniplayer_y);

/* IMAGE LINKED LIST */
t_img		*ft_mlx_init_image(t_mlx *mlx, \
	unsigned int x, unsigned int y, char *label);
int			ft_mlx_add_to_img_list(t_mlx *mlx, t_img *img);
int			ft_mlx_img_list_total_index(t_mlx *mlx);
void		*ft_mlx_get_image_by_label(t_mlx *mlx, char *label);

// get_map_settings.c
int			get_raw_map_settings(t_raw_map *map);
int			get_settings(t_settings *settings, char **raw_cfg);

/* PARSING */
int	input_parsing(int argc, char **argv);

/* UTILS */
char		**ft_split_spaces(char const *s);
int			ft_strcmp(char *str, char *str2);
int			int_strrchr(const char *str, char c);

/* CLEANUP */
void		*free_raw_map(t_raw_map *map);

#endif //CUB3D_H
