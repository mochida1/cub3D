/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:57:32 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/14 18:56:52 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <fcntl.h>		// open
#include <unistd.h>		// close, read, write
#include <stdio.h>		// printf
#include <stdlib.h>		// malloc, free, exit
#include <errno.h>		// perror
#include <string.h>		// strerror

# include "../libft/libft.h"
#include "cub_utils.h"
#include "cub_defs.h"

/* MAP UTILS*/
t_raw_map	*init_map(char *path_to_map);
void		*detroy_map(t_raw_map *map);
void		map_disassemble(t_raw_map *map);
void		get_map_raw_layout(t_raw_map *map);

#endif //CUB3D_H
