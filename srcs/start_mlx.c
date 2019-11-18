/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 02:56:13 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/18 02:56:25 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw()
{
	double posX = g_data.posx, posY = g_data.posy;
	double dirX = -0.6, dirY = 0;
	double planeX = 0, planeY = 0.66;

	// double time = 0;
	// double oldTime = 0;
	while (1)
	{
		int	x = -1, w = g_data.window.width;
		int h = g_data.window.height;
		while (++x < w)
		{
			double cameraX = 2 * x / (double)w - 1;
			double rayDirX = dirX + planeX * cameraX;
			double rayDirY = dirY + planeY * cameraX;
			
			int	mapX = (int)posX;
			int	mapY = (int)posY;

			double sideDistX;
			double sideDistY;

			double deltaDistX = fabs(1 / rayDirX);
			double deltaDistY = fabs(1 / rayDirY);
			double perpWallDist;

			int stepX;
			int stepY;

			int hit = 0;
			int side;

			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (posX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (posX + 1.0 - mapX) * deltaDistX;
			}
			if (rayDirY < 0)
		    {
		    	stepY = -1;
				sideDistY = (posY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - posY) * deltaDistY;
			}

			while (hit == 0)
			{
				if (sideDistX < sideDistY)
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
				if (g_data.map[mapX][mapY] != '0')
					hit = 1;
			}
			if (side == 0)
				perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
			else
				perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
			int lineHeight = (int)(h / (perpWallDist));

			//calculate lowest and highest pixel to fill in current stripe
			int drawStart = -lineHeight / 2 + h / 2;
			if(drawStart < 0)drawStart = 0;
			int drawEnd = lineHeight / 2 + h / 2;
			if(drawEnd >= h)drawEnd = h - 1;

			int color = 0255000000;
			if (side == 1)
				color /= 2;
			int y;
			y = -1;
			printf("dist: %f | height: %d | h: %d\n", perpWallDist, lineHeight, h);
			ft_printf("drawStart: %d | drawEnd: %d\n", drawStart, drawEnd);
			while (y++ < h)
			{
				if (y > drawStart && y < drawEnd)
					mlx_pixel_put(g_data.window.mlx, g_data.window.win, x, y, color);
				else
					mlx_pixel_put(g_data.window.mlx, g_data.window.win, x, y, 0255255255);
			}
		}
		break ;
	}
}

int		start_mlx(void)
{
	g_data.window.mlx = mlx_init();
	g_data.window.win = mlx_new_window(g_data.window.mlx, g_data.window.width, g_data.window.height, "Ta soeur");
	draw();
	mlx_loop(g_data.window.mlx);
	return (1);
}
