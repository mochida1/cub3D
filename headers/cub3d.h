/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:57:32 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/21 17:18:41 by hmochida         ###   ########.fr       */
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

#endif //CUB3D_H
