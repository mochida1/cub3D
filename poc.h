/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:00:33 by hmochida          #+#    #+#             */
/*   Updated: 2023/01/28 18:41:40 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POC_H
# define POC_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include <string.h>


#define FALSE 0
#define TRUE 1

#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24

#define MOVESPEED 0.1
#define ROTSPEED 5 * 0.01745329251
#define COS5DEG	0.99619469809
#define SIN5DEG	0.08715574274

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

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_heigh;
	int		win_width;
	t_img	*img_list_head;
}	t_mlx;

# define C_RED		0xff0000
# define C_GREEN	0x00ff00
# define C_BLUE		0x0000ff
# define C_YELLOW	0xffff00
# define C_WHITE	0xffffff
# define C_CEIL		0xffddff
# define C_FLOOR	0x00ffdd

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

#endif
