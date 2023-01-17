/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_defs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:09:00 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/17 20:44:09 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_DEFS_H
# define CUB_DEFS_H

typedef struct s_raw_map
{
	char			**raw_map_data;
	unsigned int	raw_map_size;
	unsigned int	raw_layout_size;
	unsigned int	raw_map_max_len;
	char			**raw_cfg;
	char			**raw_layout;
}	t_raw_map;

typedef struct s_configs
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	floor_colour[3];
	char	ceiling_colour[3];
}	t_configs;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}	t_mlx;

/* KEY PRESS CODES*/
# ifndef X_KEYPRESS
#  define X_KEYPRESS 2
# endif //X_KEYPRESS
# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_Q		113
# define KEY_E		101
# define KEY_R		114
# define KEY_F		102
# define KEY_Z		122
# define KEY_C		99
# define KEY_I		105
# define KEY_O		111
# define KEY_P		122
# define KEY_SPACE	32
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define RED_X		17

#endif // CUB_DEFS_H
