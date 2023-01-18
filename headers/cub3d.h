/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:57:32 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/17 20:28:12 by viferrei         ###   ########.fr       */
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

# include "../libft/libft.h"
# include "cub_utils.h"
# include "cub_defs.h"

// init_map.c
t_raw_map	*init_map(char *path_to_map);
void		*destroy_map(t_raw_map *map);

// get_map_settings.c
int			get_map_setttings(t_raw_map *map);
int			get_settings(t_settings *settings, char **raw_cfg);

#endif //CUB3D_H
