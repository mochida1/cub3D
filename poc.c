/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:03:02 by hmochida          #+#    #+#             */
/*   Updated: 2023/02/04 16:37:45 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "poc.h"

void	key_esc(t_mlx *mlx);
int	red_x_close(t_mlx *mlx);
int	keymap00(int keycode, t_mlx *mlx);
int	keymap01(int keycode, t_mlx *mlx);
int	key_press(int keycode, t_mlx *mlx);
int render_images(t_mlx *mlx);
void	event_handler(t_mlx *mlx);
static int	protec_draw_pos(int x, int y, t_img *img);
void	ft_mlx_putpix(int x, int y, int color, t_img *img);
void create_image(t_mlx *mlx);

double posX = 20, posY = 5;  //x and y start position
double dirX = -1, dirY = 0; //initial direction vector
double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane
int worldMap[mapWidth][mapHeight] =
	{
	{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
	{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
	{4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	{4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
	{4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
	{4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
	{4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
	{4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
	{4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
	{4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
	{4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
	{6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
	{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
	{6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
	{4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
	{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
	{4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
	{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
	{4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
	{4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
	{4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
	{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
	{4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
	};

int main(void)
{
	t_mlx	*mlx;
	t_img	*img;

	mlx = calloc(1, sizeof(t_mlx));
	img = calloc(1, sizeof(t_img));
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, screenWidth, screenHeight, "POCPOC");
	img->w = screenWidth;
	img->h = screenHeight;
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, img->w, img->h);
	mlx->img_list_head = img;
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->sz_line, &img->endian);
	event_handler(mlx);
	mlx_do_key_autorepeaton(mlx->mlx_ptr);

	create_image(mlx);

	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
	printf ("ok\n");
	return (0);
}

/******************************************************************/
/******************************************************************/

void create_image(t_mlx *mlx)
{
	int w = screenWidth;
	int h = screenHeight;
	for(int x = 0; x < w; x++)
	{
	//calculate ray position and direction
		double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;
		//which box of the map we're in
		int mapX = (int)posX;
		int mapY = (int)posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		double deltaDistX = ((rayDirX == 0) ? 1e30 : fabs(1 / rayDirX));
		double deltaDistY = ((rayDirY == 0) ? 1e30 : fabs(1 / rayDirY));

		double perpWallDist;
		int stepX;
		int stepY;

		int hit = 0;
		int side;
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		while(hit == 0)
		{
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if(worldMap[mapX][mapY] > 0)
				hit = 1;
			if(side == 0)
				perpWallDist = (sideDistX - deltaDistX);
			else
				perpWallDist = (sideDistY - deltaDistY);
		}

		int lineHeight = (int)(h / perpWallDist);
		int drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0) drawStart = 0;
			int drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h) drawEnd = h - 1;
		int color;
		switch(worldMap[mapX][mapY])
		{
			case 1:  color = C_RED;    break; //red
			case 2:  color = C_GREEN;  break; //green
			case 3:  color = C_BLUE;   break; //blue
			case 4:  color = C_WHITE;  break; //white
			default: color = C_YELLOW; break; //yellow
		}
		// printf ("Color: 0x%06X\n", color);
		if(side == 1)
		{
			color = color / 2;
		}
		//draw the pixels of the stripe as a vertical line
		int	count = 0;
		while (count < drawStart)
		{
			ft_mlx_putpix(x, count, C_CEIL, mlx->img_list_head);
			count++;
		}
		count = 0;
		while (count < drawEnd - drawStart)
		{
			ft_mlx_putpix(x, drawStart + count, color, mlx->img_list_head);
			count++;
		}
		while (count < screenHeight)
		{
			ft_mlx_putpix(x, drawStart + count, C_FLOOR, mlx->img_list_head);
			count++;
		}
	}
}

void	key_esc(t_mlx *mlx)
{
	printf("\033[31;1mClosing Cub32...\033[0m\n");

	// mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);

	printf("\033[32;1mCub3D closed successfully.\033[0m\n");
	exit (0);
}

int	red_x_close(t_mlx *mlx)
{
	printf("\033[31;1mClosing Cub32...\033[0m\n");

	// mlx_destroy_image(img->mlx_ptr, img->img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);

	printf("\033[32;1mCub3D closed successfully.\033[0m\n");
	exit (0);
	return (0);
}

/*
** actions for keycodes ESC, Left and Right arrows.
*/
int	keymap00(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		key_esc(mlx);
	else if (keycode == KEY_LEFT)
	{
		double oldDirX = dirX;
		double oldPlaneX = planeX;
		dirX = dirX * 0.99619469809 - dirY * 0.08715574274;
		dirY = oldDirX * 0.08715574274 + dirY * 0.99619469809;
		planeX = planeX * 0.99619469809 - planeY * 0.08715574274;
		planeY = oldPlaneX * 0.08715574274 + planeY * 0.99619469809;
		// dirX = dirX * cos.(rotSpeed) - dirY * sin.(rotSpeed);
		// dirY = oldDirX * sin.(rotSpeed) + dirY * cos.(rotSpeed);
		// planeX = planeX * cos.(rotSpeed) - planeY * sin.(rotSpeed);
		// planeY = oldPlaneX * sin.(rotSpeed) + planeY * cos.(rotSpeed);
		memset((char *)mlx->img_list_head->data, 0, mlx->img_list_head->w * mlx->img_list_head->h * mlx->img_list_head->bpp / 8);
		create_image(mlx);
		// mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_list_head->img_ptr, 0, 0);
		return (0);
	}
	else if (keycode == KEY_RIGHT)
	{
		double oldDirX = dirX;
		dirX = dirX * 0.99619469809 - dirY * -0.08715574274;
		dirY = oldDirX * -0.08715574274 + dirY * 0.99619469809;
		// dirX = dirX * cos.(-ROTSPEED) - dirY * sin.(-ROTSPEED);
		// dirY = oldDirX * sin.(-ROTSPEED) + dirY * cos.(-ROTSPEED);
		double oldPlaneX = planeX;
		planeX = planeX * 0.99619469809 - planeY * -0.08715574274;
		planeY = oldPlaneX * -0.08715574274 + planeY * 0.99619469809;
		// planeX = planeX * cos.(-ROTSPEED) - planeY * sin.(-ROTSPEED);
		// planeY = oldPlaneX * sin.(-ROTSPEED) + planeY * cos.(-ROTSPEED);
		memset((char *)mlx->img_list_head->data, 0, mlx->img_list_head->w * mlx->img_list_head->h * mlx->img_list_head->bpp / 8);
		create_image(mlx);
		// mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_list_head->img_ptr, 0, 0);
		return (0);
	}
	return (1);
}

/*
** placeholder. actions for keycodes W, A, S , D
*/
int	keymap01(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_A)
	{
		double	mv_dirX;
		double	mv_dirY;
		mv_dirX = dirX * 0 - dirY * 1;
		mv_dirY = dirX * 1 + dirY * 0;

		if(worldMap[(int)(posX + mv_dirX * (MOVESPEED * 1.1 ))][(int)posY] == FALSE)
			posX += mv_dirX * MOVESPEED;
		if(worldMap[(int)posX][(int)(posY + mv_dirY * (MOVESPEED * 1.1 ))] == FALSE)
			posY += mv_dirY * MOVESPEED;
		create_image(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_list_head->img_ptr, 0, 0);
		return (0);
	}
	else if (keycode == KEY_S)
	{
		if(worldMap[(int)(posX + dirX * -1 * (MOVESPEED * 1.1 ))][(int)posY] == FALSE)
			posX += dirX * - MOVESPEED;
		if(worldMap[(int)posX][(int)(posY + dirY * -1 * (MOVESPEED * 1.1 ))] == FALSE)
			posY += dirY * - MOVESPEED;
		create_image(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_list_head->img_ptr, 0, 0);
		return (0);
	}
	else if (keycode == KEY_D)
	{
		double	mv_dirX;
		double	mv_dirY;
		mv_dirX = dirX * 0 - dirY * 1;
		mv_dirY = dirX * 1 + dirY * 0;

		if(worldMap[(int)(posX + mv_dirX * -1 * (MOVESPEED * 1.1 ))][(int)posY] == FALSE)
			posX += mv_dirX * -MOVESPEED;
		if(worldMap[(int)posX][(int)(posY + mv_dirY * -1 * (MOVESPEED * 1.1 ))] == FALSE)
			posY += mv_dirY * -MOVESPEED;
		create_image(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_list_head->img_ptr, 0, 0);
		return (0);
	}
	else if (keycode == KEY_W)
	{
		if(worldMap[(int)(posX + dirX * (MOVESPEED * 1.1 ))][(int)posY] == FALSE)
			posX += dirX * MOVESPEED;
		if(worldMap[(int)posX][(int)(posY + dirY * (MOVESPEED * 1.1 ))] == FALSE)
			posY += dirY * MOVESPEED;
		create_image(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_list_head->img_ptr, 0, 0);
		return (0);
	}
	return (1);
}

int	key_press(int keycode, t_mlx *mlx)
{
	int	i;

	i = 0;
	memset((char *)mlx->img_list_head->data, 0, mlx->img_list_head->w * mlx->img_list_head->h * mlx->img_list_head->bpp / 8);
	i = keymap00(keycode, mlx);
	if (i)
		i = keymap01(keycode, mlx);
	return (0);
}

int render_images(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_list_head->img_ptr, 0, 0);
	return (0);
}


void	event_handler(t_mlx *mlx)
{
	printf("Registering MLX hooks\n");
	// mlx_key_hook(mlx->win_ptr, key_press, mlx);
	mlx_hook(mlx->win_ptr, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->win_ptr, RED_X, 1L << 17, red_x_close, mlx);
	mlx_expose_hook(mlx->win_ptr, render_images, mlx);
}

/*
	prevents ft_mlx_putpix from drawing pixels offscreen. Thus preventing wrong
	pixles overwrites and/or segfaults.
*/
static int	protec_draw_pos(int x, int y, t_img *img)
{
	if (y < 0 || x < 0)
		return (0);
	if (y > img->h || x > img->sz_line
		/ (img->bpp / 8))
		return (0);
	return (1);
}

/*
	Puts a pixel on image data buffer at X, Y;
*/
void	ft_mlx_putpix(int x, int y, int color, t_img *img)
{
	char	*dst;

	if (!(protec_draw_pos(x, y, img)))
		return ;
	dst = img->data + (y * img->sz_line + x * (img->bpp / 8));
	*(unsigned int *) dst = color;
}
		printf("IMAGE: %s ", temp->label);
		printf("winx: %d winy: %d\n", temp->win_x, temp->win_y);
