/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:57:32 by hmochida          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/21 17:25:35 by viferrei         ###   ########.fr       */
=======
/*   Updated: 2023/01/14 18:56:52 by hmochida         ###   ########.fr       */
>>>>>>> main
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

<<<<<<< HEAD
// init_map.c
=======
/* MAP UTILS*/
>>>>>>> main
t_raw_map	*init_map(char *path_to_map);
void		*detroy_map(t_raw_map *map);
void		map_disassemble(t_raw_map *map);
void		get_map_raw_layout(t_raw_map *map);

// get_map_settings.c
int			get_raw_map_settings(t_raw_map *map);
int			get_settings(t_settings *settings, char **raw_cfg);

/* UTILS */
char		**ft_split_spaces(char const *s);
int			ft_strcmp(char *str, char *str2);

#endif //CUB3D_H
