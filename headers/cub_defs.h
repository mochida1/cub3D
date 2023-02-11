/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_defs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:09:00 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/11 18:04:23 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_DEFS_H
# define CUB_DEFS_H

# ifndef SUCCESS
#  define SUCCESS 1
# endif //SUCCESS

# ifndef FAIL
#  define FAIL 0
# endif

# ifndef FALSE
#  define FALSE 0
# endif //FALSE

# ifndef TRUE
#  define TRUE 1
# endif //TRUE

typedef struct s_raw_map
{
	char			**raw_map_data;
	unsigned int	raw_map_size;
	unsigned int	raw_layout_size;
	unsigned int	raw_map_max_len;
	char			**raw_cfg;
	char			**raw_layout;
}	t_raw_map;

typedef struct s_img
{
	char		*label;
	void		*img_ptr;
	char		*data;
	char		hide;
	int			index;
	int			h;
	int			w;
	int			bpp;
	int			sz_line;
	int			endian;
	int			win_x;
	int			win_y;
	void		*next;
}	t_img;

typedef struct s_settings
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color[3];
	int		ceiling_color[3];
}	t_settings;

typedef struct s_textures
{
	void	*tx_img_ptr;
	char	*data;
	int		w;
	int		h;
	int		bpp;
	int		sz_line;
	int		endian;
	double	step_size;
	double	position;
}	t_tx;

typedef struct s_cube
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camera;
	double	mapx;
	double	mapy;
	double	ray_dirx;
	double	ray_diry;
	double	side_distx;
	double	side_disty;
	double	delta_x;
	double	delta_y;
	double	perp_dist;
	int		tx_x;
	int		stepx;
	int		stepy;
	int		side;
	int		wall_h;
	int		wall_start;
	int		wall_end;
	int		wall_face;
	int		color;
}	t_cube;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_heigh;
	int			win_width;
	t_img		*img_list_head;
	t_cube		*cu;
	t_raw_map	*map;
	t_settings	*settings;
	t_tx		*tx;
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

/* WALL FACING DIRECTION */
# define WALL_NORTH	0
# define WALL_SOUTH	1
# define WALL_WEST	2
# define WALL_EAST	3

/* COLOURS */
# define C_WHITE	0xffffff
# define C_BLACK	0x000000
# define C_RED		0xff0000
# define C_GREEN	0x00ff00
# define C_BLUE		0x0000ff
# define C_CYAN		0x00ffff
# define C_MAGENTA	0xff00ff
# define C_YELLOW	0xffff00
# define C_LPINK	0xffa0ff
# define C_LLPINK	0xffddff
# define C_PURP		0x880088
# define C_TEST		0xFFFFFF
# define C_BROWN	0x3d251e

/* ---------CONFIGS--------- */
# define WINDOW_W		640
# define WINDOW_H		480
# define PLANE_DIST		0.66
# define MM_SCALE		2 // minimap scaling factor
/* ------MINIMAP COORDS----- */
# define MINIMAP_X		5
# define MINIMAP_Y		10

/* -----------XPM------------*/
# define XPM_W			64
# define XPM_H			64
# define NORTH			0
# define SOUTH			1
# define WEST			2
# define EAST			3

/* --------CONSTANTS--------- */
# define COS5DEG		0.99619469809
# define SIN5DEG		0.08715574274
# define COS90DEG		0
# define SIN90DEG		1
# define COS180DEG		1
# define SIN180DEG		0
# define MOVESPEED		0.1
# define COLISION_NONE	0
# define COLISION_Y		1
# define COLISION_X		2

#endif // CUB_DEFS_H
