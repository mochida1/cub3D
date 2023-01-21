/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_defs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:09:00 by hmochida          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/21 18:19:48 by viferrei         ###   ########.fr       */
=======
/*   Updated: 2023/01/14 18:07:40 by hmochida         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_DEFS_H
# define CUB_DEFS_H

# define SUCCESS 1
# define FAIL 0

typedef struct s_raw_map
{
	char			**raw_map_data;
	unsigned int	raw_map_size;
	unsigned int	raw_layout_size;
	unsigned int	raw_map_max_len;
	char			**raw_cfg;
	char			**raw_layout;
}	t_raw_map;

<<<<<<< HEAD
typedef struct s_settings
=======
typedef struct	s_configs
>>>>>>> main
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
<<<<<<< HEAD
	int		floor_color[3];
	int		ceiling_color[3];
}	t_settings;
=======
	char	floor_colour[3];
	char	ceiling_colour[3];
}	t_configs;
>>>>>>> main

#endif // CUB_DEFS_H
